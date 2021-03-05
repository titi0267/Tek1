/*
** EPITECH 2021
** error_handling.c
** File description
** duo stumper
*/

#include "../include/my.h"

int error_argnbr(int ac, char **av)
{
    int arg2_len = 0;
    int arg3_len = 0;

    if (ac != 4)
        return (84);
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] != '.' && av[2][i] != '#' && av[2][i] != '@')
            return (84);
        arg2_len++;
    }
    for (int i = 0; av[3][i] != '\0'; i++) {
        if (av[3][i] != '.' && av[3][i] != '#' && av[3][i] != '@')
            return (84);
        arg3_len++;
    }
    if (arg2_len != arg3_len)
        return (84);
}

int error_arg1(int ac, char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] <= 48 || av[1][i] >= 57)
            return (84);
    }
}
