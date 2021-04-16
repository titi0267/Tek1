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
    if (ac < 4) {
        write(2, "missing arguments\n", 19);
        exit(84);
    }
    if (av[1][0] != '-' && av[1][1] != 'f') {
        write(2, "miss -f\n", 9);
        exit(84);
    }
}

void error_next(int ac, char **av, duo_stp_t *duo)
{
    if (ac == 4) {
        duo->size = 8;
        if (av[3][0] != '-' && av[3][1] != 's') {
            write(2, "miss -s\n", 9);
            exit(84);
        }
    }
    if (ac == 5) {
        if (av[4][0] > 57 || av[4][0] < 48) {
            write(2, "size must be a number\n", 22);
            exit(84);
        }
        duo->size = my_getnbr(av[4]);
    }
}

void arr_to_small(duo_stp_t *duo)
{
    if (duo->size < duo->char_nbr - 1)
        exit(84);
}
