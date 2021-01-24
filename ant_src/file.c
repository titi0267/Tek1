/*
** EPITECH PROJECT, 2020
** map  by Timothy CONIEL
** File description:
** map.c
*/

#include "../include/my.h"

int read_map_next(ant_t *ant, int fd)
{
    ssize_t read_ret = 0;

    read_ret = read(fd, ant->str, ant->buffer_size);
    if (read_ret == -1)
        my_printf("Couldn't read the ant\n");
    return (read_ret);
}

int read_map(ant_t *ant, char *filepath)
{
    struct stat buff;
    ssize_t read_ret = 0;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || stat(filepath, &buff) == -1) {
        my_printf("Couldn't open the file because of a wrong filepath\n");
        return (-1);
    }
    ant->buffer_size = buff.st_size + 1;
    ant->str = malloc(sizeof(char) * ant->buffer_size);
    if (ant->str == NULL) {
        my_printf("Malloc didn't worked as expected\n");
        return (-1);
    }
    read_ret = read_map_next(ant, fd);
    if (read_ret == -1)
        return (-1);
    ant->str[ant->buffer_size - 1] = '\0';
    close(fd);
    return (0);
}

int store_car(ant_t *ant, int x)
{
    int c = 0;
    int i = 0;

    ant->store = malloc(sizeof(char) * ant->buffer_size);
    if (ant->store == NULL)
        return (-1);
    for (int f = 0; f < ant->buffer_size; f++)
        ant->store[f] = NULL;
    for (; ant->str[c] != '\0'; c++) {
        for (; x <= c; x++) {
            if (ant->store[x] == ant->str[c])
                break;
            if (x == c) {
                ant->store[i] = ant->str[c];
                i++;
            }
        }
        x = 0;
    }
    ant->store[i] = '\0';
    return (0);
}

int store_map(ant_t *ant, int c, int t)
{
    store_car(ant, 0);
    ant->line = malloc(sizeof(char *) * ant->buffer_size);
    if (ant->line == NULL)
        return (-1);
    for (; ant->store[c] != '\0'; c++) {
        ant->line[c] = malloc(sizeof(char) * 100000);
        if (ant->line[c] == NULL)
            return (-1);
        for (int x = 0; ant->str[x] != '\0'; x++) {
            if (ant->store[c] == ant->str[x]) {
                ant->line[c][t] = ant->str[x];
                t++;
            }
        }
        ant->line[c][t] = '\0';
        t = 0;
    }
    ant->diff_let = c;
    ant->line[c] = NULL;
    return (0);
}

int which_map(char **av, ant_t *ant)
{
    if (read_map(ant, av[1]) == 0) {
        if (store_map(ant, 0, 0) == 0)
            return (0);
        else {
            my_printf("Malloc didn't worked as expected\n");
            return (-1);
        }
    } else
        return (-1);
    return (0);
}
