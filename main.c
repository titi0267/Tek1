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
        initial_square(buffer, info);
    }
    return (0);
}

int bsq(char *filepath)
{
    int x = 1;

    buffer_size_t *info = malloc(sizeof(buffer_size_t));
    char *buffer = fs_understand_return_of_read(filepath, info);
    if (buffer == NULL)
        return (84);
    x = where_is(buffer, info);
    if (x == 0)
        for (int i = info->nbr; buffer[i] != '\0'; i++)
        my_putchar(buffer[i]);
    free(buffer);
    return (0);
}

int main(int ac, char **av)
{

    if (ac != 2)
        return (84);
    return (bsq(av[1]));
}