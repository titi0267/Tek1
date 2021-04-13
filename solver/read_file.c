/*
** EPITECH PROJECT, 2020
** rd by Timothy CONIEL & Tom NOMINE
** File description:
** rd.c
*/

#include "include/solve.h"

void counter(read_t *rd)
{
    rd->line_nbr = 0;
    rd->char_nbr = 0;

    for (int i = 0; rd->buffer[i] != '\0'; i++) {
        if (rd->buffer[i] == '\n' && rd->line_nbr == 0)
            rd->char_nbr = i;
        if (rd->buffer[i] == '\n')
            rd->line_nbr++;
    }
    rd->line_nbr += 1;
}

int store_maze(read_t *rd)
{
    int i = 0;
    int d = 0;
    int c = 0;

    if ((rd->line = malloc(sizeof(char *) * (rd->line_nbr + 1))) == NULL)
        return (ERROR);
    while (d != rd->line_nbr) {
        if ((rd->line[d] = malloc(sizeof(char) * (rd->char_nbr + 2))) == NULL)
            return (ERROR);
        while (rd->buffer[i] != '\n' && rd->buffer[i] != '\0') {
            rd->line[d][c] = rd->buffer[i];
            c++;
            i++;
        }
        rd->line[d][c] = '\n';
        rd->line[d][c + 1] = '\0';
        i++;
        d++;
        c = 0;
    }
    rd->line[d] = NULL;
    return (0);
}

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
    if (stat_func(rd, av) == ERROR)
        return (my_puterr("Couldn't use stat\n"));
    rd->buffer = malloc(sizeof(char) * rd->buffer_size + 1);
    if ((read_ret = read(fd, rd->buffer, rd->buffer_size)) == -1)
        return (my_puterr("Couldn't reads the file\n"));
    rd->buffer_size = read_ret;
    rd->buffer[rd->buffer_size] = '\0';
    close(fd);
    counter(rd);
    if (store_maze(rd) == ERROR)
        return (ERROR);
    return (0);
}

