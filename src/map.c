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
#include <fcntl.h>

int read_map(map_t *buff, infin_number_t *info)
{
    //buff->buffer = malloc(sizeof(char *) * buff->buffer_size);
    int fd = open("map", O_RDONLY);
    my_put_nbr(fd, info);
    if (fd == -1)
        return (84);
/*
    my_printf("my positions:\n");
    while (read(fd, buff->buffer, buff->buffer_size) != (0 || -1)) {
        buff->buffer_size++;
    }
    buff->buffer[buff->buffer_size] = '\0';*/
    return (0);
}