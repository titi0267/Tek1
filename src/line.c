/*
** EPITECH PROJECT, 2021
** line by Timothy CONIEL & Eliot WALDVOGEL
** File description:
** line.c
*/
#include "../include/my.h"

void line(char **av, infin_number_t *info)
{
    my_printf("Line passing through the point ");
    my_printf("(%i, %i, %i) ", info->xp, info->yp, info->zp);
    my_printf("and parallel to the vector ");
    my_printf("(%i, %i, %i)\n", info->xv, info->yv, info->zv);
}