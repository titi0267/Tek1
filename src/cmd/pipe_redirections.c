/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** pipes
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "mysh.h"

int setup_pipes(int fds[3], char next, shell_t *shell)
{
    int pipefd[2];

    if (next) {
        pipe(pipefd);
        close(fds[1]);
        check_pipe_fd_validity(pipefd);
        if (pipefd[0] == -1 || pipefd[1] == -1)
            return (1);
        fds[2] = pipefd[0];
        fds[1] = pipefd[1];
    } else if (fds[1] != 1) {
        close(fds[1]);
        fds[1] = shell->stdout;
    }
    return (0);
}

void check_pipe_fd_validity(int pipefd[2])
{
    if (pipefd[0] == 0) {
        pipefd[0] = dup(0);
        close(0);
    }
    if (pipefd[1] == 1) {
        pipefd[1] = dup(1);
        close(1);
    }
}