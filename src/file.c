/*
** EPITECH PROJECT, 2020
** map  by Timothy CONIEL
** File description:
** map.c
*/

#include "../include/my.h"

int read_map_next(map_t *buff, int fd, int read_ret)
{
    read_ret = read(fd, buff->buffer, buff->buffer_size);
    if (read_ret != buff->buffer_size) {
        my_printf("Couldn't read the buffer\n");
        return (read_ret);
    }
    return (read_ret);
}

int read_map(map_t *buff, char *filepath)
{
    int read_ret = 0;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        my_printf("Couldn't open the file because of a wrong filepath\n");
        return (-1);
    }
    buff->buffer_size = 10;       //change malloc value (nbr char on file)
    buff->buffer = malloc(sizeof(char) * buff->buffer_size + 1);
    if (buff->buffer == NULL) {
        my_printf("Malloc didn't worked as expected\n");
        return (-1);
    }
    read_ret = read_map_next(buff, fd, read_ret);
    if (read_ret != buff->buffer_size)
        return (-1);
    buff->buffer[buff->buffer_size] = '\0';
    close(fd);
    return (0);
}

int store_map(map_t *buff)
{
    int i = 0;
    int e = 0;
    int c = 0;

    buff->line = malloc(sizeof(char *) * 12);   //change malloc value (nbr lines)
    if (buff->line == NULL)
        return (-1);
    for (;e != 11; i++, e++) {
        buff->line[e] = malloc(sizeof(char) * 139); //change malloc value (nbr char per line)
        if (buff->line[e] == NULL)
            return (-1);
        for (;buff->buffer[i] != '\n'; i++, c++)
            buff->line[e][c] = buff->buffer[i];
        buff->line[e][c] = '\n';
        buff->line[e][c + 1] = '\0';
        c = 0;
    }
    buff->line[e] = NULL;
    return (0);
}

void print_usage(void)
{
    my_printf("Print -h arg");
}

int wich_map(int ac, char **av, map_t *buff)
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
        if (read_map(buff, av[1]) == 0) {
            if (store_map(buff) == 0)
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
