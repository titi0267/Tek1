/*
** EPITECH PROJECT, 2020
** map  by Timothy CONIEL
** File description:
** map.c
*/
#include "../include/my.h"

int read_map(map_t *buff)
{
    int read_ret;
    int fd = open("png/map.txt", O_RDONLY);

    if (fd == -1)
        return (-1);
    buff->buffer_size = 1518;
    buff->buffer = malloc(sizeof(char) * buff->buffer_size + 1);
    if (buff->buffer == NULL)
        return (-1);
    read_ret = read(fd, buff->buffer, buff->buffer_size);
    if (read_ret != buff->buffer_size)
        return (-1);
    buff->buffer[buff->buffer_size] = '\0';
    close (fd);
    return(0);
}

int store_map(map_t *buff)
{
    int i = 0;
    int l = 0;
    int c = 0;

    buff->line = malloc(sizeof(char *) * 12);
    if (buff->line == NULL)
        return (-1);
    while (l != 11) {
        buff->line[l] = malloc(sizeof(char) * 139);
        if (buff->line[l] == NULL)
            return (-1);
        while (buff->buffer[i] != '\n') {
            buff->line[l][c] = buff->buffer[i];
            c++;
            i++;
        }
        buff->line[l][c] = '\n';
        buff->line[l][c + 1] = '\0';
        i++;
        l++;
        c = 0;
    }
    buff->line[l] = NULL;
    return (0);
}

int print_map(map_t *buff)
{
    int l = 0;
    int x = read_map(buff);
    int y = store_map(buff);

    if (x != 0 || y != 0)
        return (-1);
    for (; l != 11; l++) {
        for (int c = 0; buff->line[l][c] != '\0'; c++)
            my_putchar(buff->line[l][c]);
    }
    return (0);
}
