/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error
*/

#include "../include/my.h"
#include <stdlib.h>

static int error_argnbr(int ac)
{
    if (ac < 2) {
        write(2, "missing arguments\n", 19);
        return (84);
    } else if (ac > 2) {
        write(2, "too much arguments\n", 20);
        return (84);
    }
    return (0);
}

int error_word_nbr(stumper_t *stp)
{
    int i = 0;

    for (int i = 0; stp->buffer[i] != '\0'; i++) {
        if (stp->buffer[i] == ' ')
            return (84);
    }
}

int error_core(int ac)
{
    if (error_argnbr(ac) == 84)
        return (84);
    return (0);
}
