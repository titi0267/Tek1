/*
** EPITECH PROJECT, 2020
** 101pong.c by Timothé CONIEL & Elliot WALDVOGEL
** File description:
** 101pong
*/

#include "../include/my_struct.h"
#include "../include/my.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int to_float(char **av, infin_number_t *info)
{
    int a = 0;
    int tab_pos = 0;
    float f = 0;

    for (int i = 1; i <= 7; ++i) {
        if (my_str_isnum(av[i]) == 0)
            return (84);
        if (my_str_isnum(av[i]) == 1) {
            a = my_getnbr(av[i]);
            f = (float) a;
            info->given[tab_pos] = f;
            tab_pos++;
        }
    }
    info->given[tab_pos] = 0;
    return (0);
}


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
    my_putstr("     n   time shift (greater than or equal to zero, integer)\n"
    );
}

int main(int ac, char **av)
{
    infin_number_t *info = malloc(sizeof(infin_number_t));

    if (av[1] != NULL && my_strcmp(av[1], "-h") == 0) {
        check_h();
        return (0);
    }
    if (ac != 8 || my_strcmp(av[1], "-h") != 0) {
        my_putstr("Invalid Syntax\n");
        return (84);
    }
    to_float(av, info);
    core101(info);
    return (0);
}