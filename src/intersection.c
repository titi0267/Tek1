/*
** EPITECH PROJECT, 2021
** intersection.c for 104intersection project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** intersection
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>

void help(void)
{
    my_puterr("USAGE\n./104intersection opt xp yp zp xv yv zv p");
    my_puterr("\n\nDESCRIPTION\n    opt             surface option: ");
    my_puterr("1 for a sphere, 2 for a cylinder, 3 for a cone\n");
    my_puterr("    (xp, yp, zp)    coordinates of a point by which the ");
    my_puterr("light ray passes through\n");
    my_puterr("    (xv, yv, zv)    coordinates of a vector parallel to the ");
    my_puterr("light ray\n");
    my_puterr("    p               parameter: radius of the sphere, radius o");
    my_puterr("f the cylinder, or \n                    angle formed by the ");
    my_puterr("cone and the Z-axis\n");
}

void arg_to_stru(infin_number_t *info, char **av)
{
    for (int i = 1; i <= 8; i++) {
        if (i == 1)
            info->opt = my_getnbr(av[i]);
        if (i == 2)
            info->xp = my_getnbr(av[i]);
        if (i == 3)
            info->yp = my_getnbr(av[i]);
        if (i == 4)
            info->zp = my_getnbr(av[i]);
        if (i == 5)
            info->xv = my_getnbr(av[i]);
        if (i == 6)
            info->yv = my_getnbr(av[i]);
        if (i == 7)
            info->zv = my_getnbr(av[i]);
        if (i == 8)
            info->p = my_getnbr(av[i]);
    }
}

void intersection_core(infin_number_t *info)
{

}

int main(int ac, char **av)
{
    infin_number_t *info = malloc(sizeof(infin_number_t));

    if (error_handling(ac, av) != 0)
        return (84);
    arg_to_stru(info, av);
    intersection_core(info);
    return (0);
}