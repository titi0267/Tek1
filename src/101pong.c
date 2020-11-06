/*
** EPITECH PROJECT, 2020
** 101pong.c by Timothé CONIEL & Elliot WALDVOGEL
** File description:
** 101pong
*/

#include "../include/my.h"
#include <stddef.h>

void check_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     x0  ball abscissa at time t -1\n");
    my_putstr("     y0  ball ordinate at time t -1\n");
    my_putstr("     z0  ball altitude at time t -1\n");
    my_putstr("     x1  ball abscissa at time t\n");
    my_putstr("     y1  ball ordinate at time t\n");
    my_putstr("     z1  ball altitude at time t\n");
    my_putstr("     n   time shift (greater than or equal to zero, integer)\n");
}

int main(int ac, char **av)
{
    if (av[1] != NULL && my_strcmp(av[1], "-h") == 0) {
        check_h();
        return (0);
    }
    if (ac != 8 && my_strcmp(av[1], "-h") != 0) {
        my_putstr("Invalid Syntax");
        return (84);
    }
}