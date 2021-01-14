/*
** EPITECH PROJECT, 2020
** map  by Timothy CONIEL
** File description:
** map.c
*/

#include "../include/my.h"
#include <stdio.h>

int read_map_next(map_t *buffer, int fd)
{
    ssize_t read_ret = 0;
    read_ret = read(fd, buffer->str, buffer->buffer_size);
    if (read_ret == -1)
        my_printf("Couldn't read the buffer\n");
    return (read_ret);
}

int read_map(map_t *buffer, char *filepath)
{
    struct stat buff;
    ssize_t read_ret = 0;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || stat(filepath, &buff) == -1) {
        my_printf("Couldn't open the file because of a wrong filepath\n");
        return (-1);
    }
    buffer->buffer_size = buff.st_size + 1;
    buffer->str = malloc(sizeof(char) * buffer->buffer_size);
    if (buffer->str == NULL) {
        my_printf("Malloc didn't worked as expected\n");
        return (-1);
    }
    read_ret = read_map_next(buffer, fd);
    if (read_ret == -1)
        return (-1);
    buffer->str[buffer->buffer_size - 1] = '\0';
    close(fd);
    return (0);
}

int store_map(map_t *buffer)
{
    int i = 0;
    int e = 0;
    int c = 0;

    buffer->line = malloc(sizeof(char *) * buffer->buffer_size);
    if (buffer->line == NULL)
        return (-1);
    while (buffer->str[i] != '\0') {
            buffer->line[e] = malloc(sizeof(char) * 100);
        if (buffer->line[e] == NULL)
            return (-1);
        for (; buffer->str[i] != ' ' && buffer->str[i] != '\n' && i < buffer->buffer_size - 1; i++, c++) {
            buffer->line[e][c] = buffer->str[i];
        }
        if (i == buffer->buffer_size - 1)
            break;
        if (buffer->str[i + 1] == ' ' && i < buffer->buffer_size - 1) {
            i++;
        }
        if (buffer->str[i + 1] != ' ' && buffer->str[i] == ' ' && i < buffer->buffer_size - 1) {
            buffer->line[e][c] = '\0';
            e++;
            i++;
        }
        c = 0;
    }
    printf("e = %i\n", e);
    buffer->line[e + 1] = 0;
    return (0);
}

void print_usage(void)
{
    my_printf("Print -h arg");
}

int wich_map(int ac, char **av, map_t *buffer)
{
    if (ac != 2) {
        my_printf("Not that much arguments as expected.\n");
        return (-1);
    }
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        print_usage();
        return (84);
    }
    if (ac == 2) {
        if (read_map(buffer, av[1]) == 0) {
            if (store_map(buffer) == 0)
                return (0);
            else {
                my_printf("Malloc didn't worked as expected\n");
                return (-1);
            }
        } else
            return (-1);
    }
    return (0);
}
