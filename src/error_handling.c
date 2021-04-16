/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** 
*/

#include "../include/my.h"
#include <unistd.h>

int error_argnbr(int ac, char **av)
{
    if (ac != 4) {
        write(2, "missing arguments\n", 19);
        return (84);
    }
    if (av[1][0] != '-' && av[1][1] != 'f') {
        write(2, "miss -f\n", 9);
        return (84);
    }
    if (ac == 3) {
        if (error_arg_one(av) == 84)
            return (84);
    }
    if (error_next(ac, av) == 84)
        return (84);
    return (0);
}

int error_arg_one(char **av)
{
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[5][i] < 48 || av[5][i] > 57) {
            write(2, "must be between 0 and 9\n", 25);
            return (84);
        }
    }
    return (0);
}

int error_next(int ac, char **av)
{
    if (ac == 5) {
        if (av[4][0] != '-' && av[4][1] != 's') {
            write(2, "miss -s\n", 9);
            return (84);
        }
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] < 97 || av[2][i] > 122) {
            write(2, "must be in the alphabet\n", 25);
            return (84);
        }
    }
    return (0);
}

int error_lowercase(int ac, char **av)
{
    for (int i = 0; av[2][0] != '\0'; i++) {
        if (av[][] 
    }
}
