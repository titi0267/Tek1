/*
** EPITECH PROJECT, 2021
** get map by Timothy CONIEL
** File description:
** get_map.c
*/

#include "../include/my.h"

int read_mapsize(map_t *map, char *filepath, int fd)
{
    struct stat buff;
    ssize_t read_ret = 0;

    if (stat(filepath, &buff) == -1)
        return (-1);
    map->size = buff.st_size;
    map->str = malloc(sizeof(char) * (buff.st_size + 2));
}

int read_map(map_t *map, char *filepath)
{
    int read_ret;
    int stat_ret;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        my_puterr("Couldn't open the file.\n");
        return (-1);
    }
    stat_ret = read_mapsize(map, filepath, fd);
    if (stat_ret == -1)
        return (-1);
    read_ret = read(fd, map->str, map->size);
    if (read_ret == -1)
        return (-1);
    if (map->str[map->size - 1] != '\n') {
        map->str[map->size] = '\n';
        map->size += 1;
    }
    map->str[map->size] = '\0';
    close (fd);
    return (0);
}
