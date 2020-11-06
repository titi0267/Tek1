/*
** EPITECH PROJECT, 2020
** print_float
** File description:
** print_float
*/

#include "../../include/my.h"

int print_float(float a)
{
    int b = (int)a;
    float c = a - b;

    c *= 100;
    int d = c;

    if (b == 100)
        my_putchar(49);
    my_put_nbr(b);
    my_putchar('.');
    my_put_nbr(d);
    if (d == 0)
        my_putchar(48);
    return (0);
}