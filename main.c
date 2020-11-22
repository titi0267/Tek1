/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** main
*/
#include "include/steps.h"
#include "include/my.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int where_is(char *buffer, buffer_size_t *info)
{
    int x = 0;

    x = no_nbr(buffer, info);
    if (x != 1)
        return (84);
    else {
        find_square(buffer, info);
        initial_square(buffer, info);
    }
    return (0);
}

int core(int ac, char **av)
{
    int fd = fs_open_file(av[1]);
    buffer_size_t *info = malloc(sizeof(buffer_size_t));
    int x;
    struct stat buff;
    stat(av[1], &buff);
    int size = buff.st_size;
    char *buffer;

    if (fd == 84)
        return (84);
    buffer = malloc(sizeof(char) * size + 1);
    fs_understand_return_of_read(fd, buffer, size);
    buffer[size] = '\0';
    x = where_is(buffer, info);
    if (x == 0)
        write(1, buffer, size);
    close(fd);
    free(buffer);
    return (0);
}

int main(int ac, char **av)
{
    int error = core(ac, av);
    if (ac != 2)
        return (84);
    if (error != 0)
        return (84);
    return (0);
}