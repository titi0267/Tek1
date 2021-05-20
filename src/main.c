/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "mysh.h"

int main(int ac, char **av, char **default_env)
{
    shell_t shell = {copy_env(default_env),
    my_strdup(""), dup(0), dup(1), 0, 1, 0, -1, 0};
    char *input = NULL;
    char **cmds = NULL;

    if (!shell.env || shell.stdin == -1 || shell.stdout == -1)
        return (84);
    set_default_path(&(shell.env));
    while (1) {
        input = read_input("$> ", 3);
        if (!input)
            return (shell.ret);
        cmds = split_commands(input);
        if (check_input(cmds))
            continue;
        errno = 0;
        execute_commands(cmds, &shell);
        free(input);
    }
    return (0);
}

void exit_program(int ret)
{
    if (isatty(0))
        write(1, "exit\n", 5);
    exit(ret);
}
