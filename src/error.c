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
    if (ac > 4) {
        write(2, "too much arguments\n", 20);
        exit(84);
    }
}
