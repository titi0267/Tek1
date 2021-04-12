/*
** EPITECH PROJECT, 2020
** rd by Timothy CONIEL & Tom NOMINE
** File description:
** rd.c
*/

#include "include/solve.h"

int stat_func(read_t *rd, char **av)
{
    struct stat buff;

    if (stat(av[1], &buff) == -1)
        return (ERROR);
    rd->buffer_size = buff.st_size + 1;
    return (0);
}

int read_maze(read_t *rd, char **av)
{
    int read_ret = 0;
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (my_puterr("Couldn't open the file\n"));
    stat_func(rd, av);
    rd->buffer = malloc(sizeof(char) * rd->buffer_size + 1);
    if ((read_ret = read(fd, rd->buffer, rd->buffer_size)) == -1)
        return (my_puterr("Couldn't reads the file\n"));
    rd->buffer_size = read_ret;
    rd->buffer[rd->buffer_size] = '\0';
    close(fd);
    return (0);
}
