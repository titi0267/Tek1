/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** file redirections
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "mysh.h"

int setup_file_redirection(char *filename,
int fds[3], int file_red, shell_t *shell)
{
    switch (file_red) {
        case READ_FILE_REDIRECT:
        return (setup_input_file(filename, fds, shell));
        case HEREDOC_REDIRECT:
        return (setup_input_heredoc(filename, fds, shell));
        case WRITE_REDIRECT:
        return (setup_output_file(filename, fds, shell));
        case WRITE_APPEND_REDIRECT:
        return (setup_output_append_file(filename, fds, shell));
    }
    return (0);
}

int setup_input_file(char *filename, int fds[3], shell_t *shell)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
        return (1);
    fds[0] = fd;
    return (0);
}

int setup_input_heredoc(char *eof, int fds[3], shell_t *shell)
{
    int pipefd[2];

    if (fds[0] != 0) {
        write(2, "Ambigous input redirect.\n", 25);
        shell->ret = 1;
        return (1);
    }
    pipe(pipefd);
    check_pipe_fd_validity(pipefd);
    heredoc(eof, pipefd[1]);
    close(pipefd[1]);
    fds[0] = pipefd[0];
    return (0);
}

int setup_output_file(char *filename, int fds[3], shell_t *shell)
{
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    int couple[2] = {fd, dup(fd)};

    if (fd == -1)
        return (1);
    check_pipe_fd_validity(couple);
    close(fds[1]);
    fds[1] = couple[0];
    fds[2] = couple[1];
    return (0);
}

int setup_output_append_file(char *filename, int fds[3], shell_t *shell)
{
    int fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
    int couple[2] = {fd, dup(fd)};

    if (fd == -1)
        return (1);
    check_pipe_fd_validity(couple);
    close(fds[1]);
    fds[1] = couple[0];
    fds[2] = couple[1];
    return (0);
}