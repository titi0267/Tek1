/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** commands
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "mysh.h"
#include "builtins.h"

/*
** Execute commands separated by ';'
** sub_cmds separated by |
** args separated by (space) and \t
** NOTE: sub_cmds should be reset every cmd separated by ';'
*/
void execute_commands(char **cmds, shell_t *shell)
{
    char *actual_cmd;
    char **sub_cmds = NULL;
    int tmp;

    if (!cmds)
        return;
    for (char **cmd = cmds; *cmd != 0; cmd++) {
        actual_cmd = *cmd;
        sub_cmds = NULL;
        shell->ret = 0;
        while (separators(&actual_cmd, &sub_cmds, shell) && sub_cmds) {
            shell->prev_pid = -1;
            execute_subcommands(sub_cmds, shell);
            tmp = wait_all_children(shell);
            shell->ret = shell->ret ? shell->ret : tmp;
        }
        dup2(shell->stdin, 0);
        dup2(shell->stdout, 1);
    }
}

/*
** Execute sub-commands separated by '|'
** fds[3] = {in, out, next_in}
*/
void execute_subcommands(char **sub_cmds, shell_t *shell)
{
    int fds[3] = {0, 1, 0};
    char *cmd = NULL;
    char **args = NULL;
    int tmp = 0;

    for (int i = 0; sub_cmds[i]; i++) {
        cmd = sub_cmds[i];
        args = split_command_into_args(cmd);
        if (check_null_cmd(args, shell) || shell->ret ||
        setup_redirections(args, fds, sub_cmds[i + 1] != 0, shell))
            break;
        tmp = execute_command(args, sub_cmds[i + 1] != 0, shell);
        shell->ret  = tmp > -1 ? tmp : shell->ret;
        close(fds[0]);
        fds[0] = fds[2];
    }
}

/*
** The ~HEART~ of this terrific, magnificent & Amazing shell <3
*/
int execute_command(char **args, char next, shell_t *shell)
{
    char *bin = NULL;
    int status = 0;

    if ((status = builtin_cmd(args, shell)) > -1) {
        return (status);
    } else if ((bin = search_binary(args, shell)) != NULL) {
        status = run_file(bin, args, next, shell);
        free(bin);
        return (0);
    } else {
        if (errno && errno != 2)
            print_err(args[0]);
        else {
            write(2, args[0], my_strlen(args[0]));
            write(2, ": Command not found.\n", 21);
        }
        return (1);
    }
}

int builtin_cmd(char **args, shell_t *shell)
{
    for (int i = 0; i < BUILTINS_NB; i++) {
        if (my_strlen(args[0]) == BUILTINS_LEN[i] &&
        !my_strcmp(args[0], BUILTINS[i])) {
            return ((BUILTINS_FCT[i])(args, shell));
        }
    }
    return (-1);
}

int check_null_cmd(char **args, shell_t *shell)
{
    if (!args) {
        if (shell->in_fd != 0 || shell->out_fd != 1) {
            write(2, "Invalid null command.\n", 22);
            shell->ret = 1;
        }
        return (1);
    }
    return (0);
}
