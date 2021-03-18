/*
** EPITECH 2021
** error_handling.c
** File description
** duo stumper
*/

#include "../include/my.h"
#include <unistd.h>

int error_argnbr(int ac, char **av)
{
    if (ac != 3) {
        write(2, "missing arguments\n", 19);
        return (84);
    }
    error_arg_one(ac, av);
}

int error_arg_one(int ac, char **av)
{
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] < 48 || av[2][i] > 57) {
            write(2, "must be between 0 and 9\n", 25);
            return (84);
        }
    }
}
