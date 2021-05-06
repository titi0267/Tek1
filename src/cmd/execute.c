/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** execute commands
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include "my.h"
#include "mysh.h"
#include "signal_errors.h"

int run_file(char *bin, char **args, char next, shell_t *shell)
{
    pid_t pid;

    if ((pid = fork()) == -1) {
        return (-1);
    } else if (pid == 0) {
        execve(bin, args, shell->env);
        exit(0);
    } else {
        return (wait_child(pid, next, shell));
    }
    return (1);
}

int wait_child(pid_t pid, char next, shell_t *shell)
{
    int status;

    if (shell->prev_pid > -1) {
        shell->prev_pid = pid;
        if (!next) {
            waitpid(pid, &status, 0);
            return (status);
        }
        return (-1);
    } else if (!next) {
        waitpid(pid, &status, 0);
        return (status);
    } else {
        shell->prev_pid = pid;
        return (-1);
    }
}

int analyse_status_value(int status)
{
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    else if (WIFSIGNALED(status)) {
        print_sig_error(status, WTERMSIG(status));
        return (0);
    }
    return (-1);
}

void print_sig_error(int status, int sig)
{
    int i = 0;

    for (; i < NB_ERRORS; i++) {
        if (SIG_ERRORS[i] == sig) {
            write(2, ERRORS[i], ERRORS_LEN[i]);
            break;
        }
    }
    if (i == NB_ERRORS)
        return;
    if (WCOREDUMP(status))
        write(2, " (core dumped)\n", 15);
    else
        write(2, "\n", 1);
}