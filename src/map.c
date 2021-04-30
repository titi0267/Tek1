/*
** EPITECH PROJECT, 2020
** Map by Timothy CONIEL & Tom NOMINE
** File description:
** map.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int read_map(stumper_t *stp, char **av)
{
    int read_ret;
    int fd = open(av[1], O_RDONLY);

    if (fd == -1) {
        write(2, "wrong file\n", 12);
        return (84);
    }
    stp->buffer_size = 1800;
    stp->buffer = malloc(sizeof(char) * stp->buffer_size + 1);
    read_ret = read(fd, stp->buffer, stp->buffer_size);
    if (read_ret == -1) {
        write(2, "wrong read\n", 12);
        return (84);
    }
    stp->buffer_size = read_ret;
    stp->buffer[stp->buffer_size] = '\0';
    close(fd);
    stp->line_nbr = nbr_line(stp->buffer);
    stp->char_nbr =  char_line(stp->buffer);
    return (0);
}

int store_map(stumper_t *stp)
{
    int i = 0;
    int d = 0;
    int c = 0;

    stp->line = malloc(sizeof(char *) * (stp->line_nbr + 1));
    while (d != stp->line_nbr) {
        stp->line[d] = malloc(sizeof(char) * (stp->char_nbr + 1));
        while (stp->buffer[i] != '\n') {
            stp->line[d][c] = stp->buffer[i];
            c++;
            i++;
        }
        stp->line[d][c] = '\n';
        stp->line[d][c + 1] = '\0';
        i++;
        d++;
        c = 0;
    }
    stp->line[d] = NULL;
    return (0);
}
