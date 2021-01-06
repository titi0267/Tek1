/*
** EPITECH PROJECT, 2021
** radius by Timothy CONIEL & Eliot WALDVOGEL
** File description:
** radius.c
*/
#include "../include/my.h"

int radius(char **av, infin_number_t *info)
{
    if (av[1][0] == '1')
        my_printf("Sphere ");
    else if (av[1][0] == '2')
        my_printf("Cylinder ");
    else {
        my_printf("Cone ");
        return (1);
    }
    my_printf("of radius %i\n", info->p);
    return (0);
}

void angle(char **av, infin_number_t *info)
{
    int x = radius(av, info);

    if (x == 1)
        printf("whit a %i degree angle\n", info->p);
}