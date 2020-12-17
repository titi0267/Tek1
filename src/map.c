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

int print_map(map_t *buff, infin_number_t *info)
{
    int l = 0;
    read_map(buff);
    store_map(buff);
    while (l != 10) {
        for (int c = 0; buff->line[l][c] != '\0'; c++) {
            my_putchar(buff->line[l][c], info);
        }
        l++;
    }
    return (0);
}

int my_charcmp(char c, infin_number_t *info)
{
    switch(c) {
    case 'A':
        return (2);
    case 'B':
        return (4);
    case 'C':
        return (6);
    case 'D':
        return (8);
    case 'E':
        return (10);
    case 'F':
        return (12);
    case 'G':
        return (14);
    case 'H':
        return (16);
    default:
        my_putstr("Invalid position\n", info);
    }
    return (-1);
}

int which_column(pos_t *where, infin_number_t *info)
{
    int f = 0;
    int i = 0;
    int x = -1;

    where->column_start = malloc(sizeof(int) * 5);
    where->column_end = malloc(sizeof(int) * 5);
    while (f != 4) {
        x = my_charcmp(where->find_pos1[f][2], info);
        if (x != -1)
            where->column_start[i] = x;
        x = my_charcmp(where->find_pos1[f][5], info);
        if (x != -1)
            where->column_end[i] = x;
        f++;
        i++;
    }
    return (0);
}

int map_p1(map_t *buff, pos_t *where, infin_number_t *info)
{
    which_column(where, info);

    //printf("The second ship ends in column %i", where->column_end[1]);
    return (0);
}