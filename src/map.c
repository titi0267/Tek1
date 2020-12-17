/*
** EPITECH PROJECT, 2020
** Map by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** map.c
*/
#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

void *read_map(map_t *buff)
{
    int read_ret;
    int fd = open("map", O_RDONLY);

    if (fd == -1)
        return (NULL);
    my_printf("my positions:\n");
    buff->buffer_size = 180;
    buff->buffer = malloc(sizeof(char) * buff->buffer_size + 1);
    read_ret = read(fd, buff->buffer, buff->buffer_size);
    if (read_ret == -1)
        return (NULL);
    buff->buffer[buff->buffer_size] = '\0';
    close (fd);
    return (0);
}

int store_map(map_t *buff)
{
    int i = 0;
    int l = 0;
    int c = 0;

    buff->line = malloc(sizeof(char *) * 11);
    while (l != 10) {
        buff->line[l] = malloc(sizeof(char) * 19);
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

void ship_map(map_t *buff, pos_t *where)
{
    int i = 0;
    read_map(buff);
    store_map(buff);
    for (; i <= 3; i++) {
        if (where->line_start[i] == where->line_end[i]) {
            buff->line[where->line_start[i]][where->column_start[i]] = 50 + i;
            for (int x = 0; x <= i && i != 0; x++)
                buff->line[where->line_start[i]][where->column_start[i] + (x * 2)] = 50 + i;
        }
        if (where->column_start[i] == where->column_end[i]) {
            buff->line[where->line_start[i]][where->column_start[i]] = 50 + i;
            for (int x = 0; x <= i && i != 0; x++)
                buff->line[where->line_start[i] + (x + 1)][where->column_start[i]] = 50 + i;
        }
        buff->line[where->line_end[i]][where->column_end[i]] = 50 + i;
    }
}

int print_map(map_t *buff, pos_t *where, infin_number_t *info)
{
    int l = 0;

    ship_map(buff, where);
    while (l != 10) {
        for (int c = 0; buff->line[l][c] != '\0'; c++) {
            my_putchar(buff->line[l][c], info);
        }
        l++;
    }
    return (0);
}
