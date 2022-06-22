/*
** EPITECH PROJECT, 2021
** duo stumper
** File description:
** fractal2.c
*/

#include "../include/my.h"

int if_one(char **av)
{
    if (my_getnbr(av[1]) != 1)
        return (1);   
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] == '@')
            my_putchar('\n');
        else
            my_putchar(av[2][i]);
    }
    my_putchar('\n');
    return (0);
}
