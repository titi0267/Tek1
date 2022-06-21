/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** error_handling.c
*/

#include "../include/my.h"
#include <unistd.h>

void error_argnbr(int ac)
{
    if (ac >= 5) {
        write(2, "too much arguments\n", 20);
        exit(84);
    }
    if (ac == 1) {
        write(2, "missing arguments\n", 19);
        exit(84);
    }
}

void find_str(int ac, char **av, stumper_t *stp)
{
    if (ac == 4) {
        if (av[1][0] != '-' && (av[1][1] != 'r' || av[1][1] != 't')) {
            write(2, "missing flag\n", 13);
            exit(84);
        }
    }
    if (ac == 5) {
        stp->arg = 4;
        stp->arg_first = 3;
        stp->t_flag = 1;
        stp->flag_r = 1;
    }
    if (ac == 3 && av[1][0] != '-' && (av[1][1] != 'r' || av[1][1] != 't')) {
        stp->arg = 2;
        stp->arg_first = 1;
    } else if (ac == 3) {
        stp->arg = 2;
        stp->arg_first = 2;
    }
    find_str_next(stp, av, ac);
}

void find_str_next(stumper_t *stp, char **av, int ac)
{
    if (ac == 2) {
        stp->arg = 1;
        stp->arg_first = 1;
    }
    if (ac == 4 && av[2][0] == '-' && (av[2][1] == 't' || av[2][1] == 'r')) {
        stp->arg = 3;
        stp->arg_first = 3;
        stp->t_flag = 1;
        stp->flag_r = 1;
    } else if (ac == 4) {
        stp->arg = 3;
        stp->arg_first = 2;
    }
}
