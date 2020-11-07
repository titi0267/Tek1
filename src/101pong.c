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
#include <string.h>

int to_float(char **av, infin_number_t *info)
{
    int tab_pos = 0;
    float f = 0;

    for (int i = 1; i <= 7; ++i) {
        if (my_str_isnum(av[i]) == 0)
            return (84);
        if (my_str_isnum(av[i]) == 1) {
            f = atof(av[i]);
            info->given[tab_pos] = f;
            tab_pos++;
        }
    }
    info->given[tab_pos] = 0;
    return (0);
}

void disp_vel(infin_number_t *info)
{
    my_putstr("The Velocity vector of this ball is :\n");
    for (int a = 0; a <= 2; a ++)
        printf("%.2f\n", info->vels[a]);
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

    int c_error = 0;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        check_h();
        return (0);
    }
    if (ac != 8 && (av[1][0] != '-' && av[1][1] != 'h')) {
        my_putstr("Invalid Syntax\n");
        return (84);
    }
    c_error = to_float(av, info);
    if (c_error == 84)
        return (84);
    core101(info);
    disp_vel(info);
    return (0);
}