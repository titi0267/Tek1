/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** redirections
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "mysh.h"

int setup_redirections(char **args, int fds[3], char next, shell_t *shell)
{
    int redirections = 0;

    if ((redirections = setup_all_file_redirection(args, fds, shell)) == -1)
        return (1);
    if (check_redirections(redirections, next, fds, shell))
        return (1);
    shell->in_fd = fds[0];
    shell->out_fd = fds[1];
    dup2(fds[0], 0);
    dup2(fds[1], 1);
    return (0);
}

int setup_all_file_redirection(char **args, int fds[3], shell_t *shell)
{
    int file_red = 0;
    char file_in = 0;
    char file_out = 0;

    while ((file_red = get_file_redirection(&args))) {
        if (!args[1]) {
            write(2, "Missing name for redirect.\n", 27);
            return (-1);
        }
        if (check_multiple_file_redirect(file_red, &file_in, &file_out) ||
        setup_file_redirection(args[1], fds, file_red, shell))
            return (-1);
        args++;
    }
    return ((file_in << 1) | file_out);
}

int get_file_redirection(char ***args)
{
    int value = 0;

    for (; **args; *args += 1) {
        if (***args == '<') {
            value = READ_FILE_REDIRECT;
            if (*(**args + 1) == '<')
                value = HEREDOC_REDIRECT;
            **args = NULL;
        } else if (***args == '>') {
            value = WRITE_REDIRECT;
            if (*(** args + 1) == '>')
                value = WRITE_APPEND_REDIRECT;
            **args = NULL;
        }
        if (value)
            return (value);
    }
    return (0);
}

int check_multiple_file_redirect(int file_red, char *file_in, char *file_out)
{
    if (file_red == READ_FILE_REDIRECT || file_red == HEREDOC_REDIRECT) {
        if (*file_in) {
            write(2, "Ambigous file redirect.\n", 24);
            return (1);
        }
        *file_in = 1;
    } else {
        if (*file_out) {
            write(2, "Ambigous file redirect.\n", 24);
            return (1);
        }
        *file_out = 1;
    }
    return (0);
}

int check_redirections(int redirections, char next, int fds[3], shell_t *shell)
{
    char file_in = redirections & 2;
    char file_out = redirections & 1;

    if (file_in && shell->in_fd != 0) {
        write(2, "Ambigous file redirect.\n", 24);
        return (1);
    }
    if (file_out) {
        if (next) {
            write(2, "Ambigous file redirect.\n", 24);
            return (1);
        }
    } else
        setup_pipes(fds, next, shell);
    return (0);
}