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
    if (ac != 3 || ac != 5) {
        write(2, "missing arguments\n", 19);
        return (84);
    }
    if ((av[1][0] != '-' && av[1][1] != 'n') || (av[3][0] != '-' && av[3][1] != 'n')) {
        write(2, "miss -n\n", 9);
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
        if (av[2][i] < 48 || av[2][i] > 57) {
            write(2, "must be between 0 and 9\n", 25);
            return (84);
        }
    }
    return (0);
}

int error_next(int ac, char **av)
{
    if (ac == 5) {
        if (av[1][0] != '-' && av[1][1] != 's') {
            write(2, "miss -s\n", 9);
            return (84);
        }
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (ac == 5 && (av[2][i] < 97 || av[2][i] > 122)) {
            write(2, "must be in the alphabet\n", 25);
            return (84);
        }
    }
    if (ac == 5)
        if (error_string_two(ac, av) == 84)
            return (84);
    return (0);
}

int error_string_two(int ac, char **av)
{
    for (int i = 0; av[4][i] != '\0'; i++) {
        if (av[4][i] < 48 || av[4][i] > 57) {
            write(2, "must be between 0 and 9\n", 25);
            return (84);
        }
    }
    return (0);
}
