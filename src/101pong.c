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
#include <math.h>

int t_is_float(char **av)
{
    for (int i = 0; av[7][i] != '\0'; i++) {
        if (av[7][i] == '.')
            return (1);
    }
    return (0);
}

int to_float(char **av, infin_number_t *info)
{
    int tab_pos = 0;
    float f = 0;

    if (av[7][0] == '-' || t_is_float(av) == 1)
        return (84);
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

void display(infin_number_t *info)
{
    my_putstr("The velocity vector of the ball is:\n(");
    printf("%.2f, %.2f, %.2f)\n", info->vels[0], info->vels[1], 
    info->vels[2]);
    printf("At time t + %.0f, ball coordinates will be:\n(", info->given[6]);
    printf("%.2f, %.2f, %.2f)\n", info->tpos[0], info->tpos[1], 
    info->tpos[2]);
    if (info->bounced == 1) {
        my_putstr("The incidence angle is:\n");
        printf("%.2f degrees\n", info->angle);
    }
    if (info->bounced == 0)
        my_putstr("The ball won’t reach the paddle.\n");
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

    if (av[1][0] == '-' && av[1][1] == 'h') {
        check_h();
        return (0);
    }
    if (ac != 8 && (av[1][0] != '-' && av[1][1] != 'h')) {
        my_putstr("Invalid Syntax\n");
        return (84);
    }
    info->c_error = to_float(av, info);
    if (info->c_error == 84) {
        my_putstr("Invalid Syntax\n");
        return (84);
    }
    core101(info);
    display(info);
    return (0);
}