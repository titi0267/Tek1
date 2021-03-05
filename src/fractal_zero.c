/*
** EPITECH PROJECT, 2021
** fractal_zero.c
** File description:
** 
*/

#include "../include/my.h"

int parse_string_zero(char **av)
{
    int f = my_getnbr(av[1]);

    if (f == '0')
        my_putchar(av[2][0]);
    my_putchar('\n');
    return (0);
}
