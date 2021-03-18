/*
** EPITECH PROJECT, 2020
** Map by Timothy CONIEL & Elliot WALDVOGEL
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
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (84);
    map->buffer_size = 1800;
    map->buffer = malloc(sizeof(char) * map->buffer_size + 1);
    read_ret = read(fd, map->buffer, map->buffer_size);
    if (read_ret == -1)
        return (84);
    map->buffer[map->buffer_size] = '\0';
    close (fd);
    return (0);
}

int store_map(map_t *map)
{
    int i = 0;
    int d = 0;
    int c = 0;

    map->line = malloc(sizeof(char *) * 11);
    while (d != 10) {
        map->line[d] = malloc(sizeof(char) * 19);
        while (map->buffer[i] != '\n') {
            map->line[d][c] = map->buffer[i];
            c++;
            i++;
        }
        map->line[d][c] = '\n';
        map->line[d][c + 1] = '\0';
        i++;
        d++;
        c = 0;
    }
    map->line[d] = NULL;
    return (0);
}
