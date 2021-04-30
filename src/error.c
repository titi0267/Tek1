/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** error
*/

#include "../include/my.h"
#include <stdlib.h>

int error_core(int ac, char **av, stumper_t *stp)
{
    error_argnbr(ac, av);
    return (0);
}

void error_argnbr(int ac, char **av)
{
    if (ac < 2) {
        write(2, "missing arguemnts\n", 19);
        exit(84);
    }
    if (ac == 2) {
        if (av[1][0] > 97 || av[1][0] < 122) {
            write(2, "must be a text\n", 16);
            exit(84);
        }
    }
}
