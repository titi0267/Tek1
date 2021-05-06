/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** error_handling.c
*/

#include "../include/my.h"
#include <unistd.h>

void error_argnbr(int ac, char **av)
{
    if (ac > 4) {
        write(2, "too much arguments\n", 20);
        exit(84);
    }
    if (ac < 1) {
        write(2, "missing arguments\n", 19);
    }
    if (av[1][0] != '-' && av[1][1] != 't') {
        write(2, "miss -t\n", 9);
        exit(84);
    }
}

void error_next(int ac, char **av, stumper_t *buffer)
{
    if (ac == 4) {
        duo->size = 8;
        if (av[2][0] != '-' && av[3][1] != 'r') {
            write(2, "miss -r\n", 9);
            exit(84);
        }
    }
}

void arr_to_small(stumper_t *buffer)
{
    if (duo->size < duo->char_nbr - 1)
        exit(84);
}
