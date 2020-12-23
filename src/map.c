/*
** EPITECH PROJECT, 2020
** map  by Timothy CONIEL
** File description:
** map.c
*/
#include "../include/my.h"

void *read_map(map_t *buff)
{
    int read_ret;
    int fd = open("png/map.txt", O_RDONLY);

    if (fd == -1)
        return (NULL);
    buff->buffer_size = 1518;
    buff->buffer = malloc(sizeof(char) * buff->buffer_size + 1);
    if (buff->buffer == NULL)
        return (NULL);
    read_ret = read(fd, buff->buffer, buff->buffer_size);
    if (read_ret == -1)
        return (NULL);
    buff->buffer[buff->buffer_size] = '\0';
    close (fd);
    return (0);
}

void *store_map(map_t *buff)
{
    int i = 0;
    int l = 0;
    int c = 0;

    buff->line = malloc(sizeof(char *) * 12);
    if (buff->line == NULL)
        return (NULL);
    while (l != 11) {
        buff->line[l] = malloc(sizeof(char) * 139);
        if (buff->line[l] == NULL)
            return (NULL);
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

    read_map(buff);
    store_map(buff);
    my_printf("my positions:\n");
    while (l != 11) {
        for (int c = 0; buff->line[l][c] != '\0'; c++) {
            my_putchar(buff->line[l][c]);
        }
        l++;
    }
    my_printf("enemy's positions:\n");
    for (int i = 0; i != 1518; i++) {
        my_putchar(buff->buffer[i]);
    }
    return (0);
}
