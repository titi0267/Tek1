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
    my_printf("enemy's positions:\n");
    buff->buffer_size = 180;
    buff->buffer = malloc(sizeof(char *) * buff->buffer_size);
    read_ret = read(fd, buff->buffer, buff->buffer_size);
    if (read_ret == -1)
        return (NULL);
    buff->buffer[buff->buffer_size] = '\0';
    //my_printf("%s\n", buff->buffer);
    return (0);
}

int enemy_map(map_t *buff)
{

}