/*
** EPITECH PROJECT, 2020
** Map by Timothy CONIEL & Eloitt WALDVOGEL
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

int assemble(map_t *buff, infin_number_t *info)
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

/*int enemy_map(map_t *buff)
{
    
}*/