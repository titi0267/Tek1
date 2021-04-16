/*
** EPITECH PROJECT, 2021
** Map by Timothy CONIEL & Tom NOMINE
** File description:
** map.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int read_map(duo_stp_t *map, char **av)
{
    int read_ret;
    int fd = open(av[2], O_RDONLY);

    if (fd == -1) {
        write(2, "wrong file\n", 12);
        return (84);
    }
    map->buffer_size = 1800;
    map->buffer = malloc(sizeof(char) * map->buffer_size + 1);
    read_ret = read(fd, map->buffer, map->buffer_size);
    if (read_ret == -1) {
        write(2, "wrong read\n", 12);
        return (84);
    }
    map->buffer_size = read_ret;
    map->buffer[map->buffer_size] = '\0';
    close(fd);
    map->line_nbr = nbr_line(map->buffer);
    map->char_nbr = nbr_char(map->buffer);
    return (0);
}
