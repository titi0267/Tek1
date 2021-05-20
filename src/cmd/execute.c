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

/*
** execve in the (non-human) child process
** in my point of view it should be rewritten so that
** instead of forcing the parent shell to constantly to call dup2 in order
** for the children to inherit its fds it is prefferred that the children
** adapt their stdin and stdout to the required output and leave shells
** stdin and stdout unchanged
*/
int run_file(char *bin, char **args, char next, shell_t *shell)
{
    if ((shell->prev_pid = fork()) == -1) {
        return (-1);
    } else if (shell->prev_pid == 0) {
        execve(bin, args, shell->env);
        exit(0);
    } else {
        return (0);
    }
    return (1);
}

int wait_all_children(shell_t *shell)
{
    int status;
    int saved_status = 0;

    while (wait(&status) > 0) {
        if (saved_status == 0 && WIFSIGNALED(status)) {
            saved_status = status;
        }
    }
    analyse_status_value(saved_status);
}
/*
** core dumped printed here
** important checks shall be done before
*/
int analyse_status_value(int status)
{
    int signal_val;

    if (!WIFSIGNALED(status))
        return (0);
    signal_val = WTERMSIG(status);
    print_sig_error(status, signal_val);
    return (1);
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