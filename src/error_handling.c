/*
** EPITECH 2021
** error_handling.c
** File description
** duo stumper
*/

#include "../include/my.h"

int error_argnbr(int ac, char **av)
{
    int arg_two_len = 0;
    int arg_three_len = 0;

    if (ac != 4)
        return (84);
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] != '.' && av[2][i] != '#' && av[2][i] != '@')
            return (84);
        arg_two_len++;
    }
    for (int i = 0; av[3][i] != '\0'; i++) {
        if (av[3][i] != '.' && av[3][i] != '#' && av[3][i] != '@')
            return (84);
        arg_three_len++;
    }
    if (arg_two_len != arg_three_len)
        return (84);
}

int error_arg_one(int ac, char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] <= 48 || av[1][i] >= 57)
            return (84);
    }
}
