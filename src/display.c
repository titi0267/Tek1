/*
** EPITECH PROJECT, 2021
** display by Timothy CONIEL & Eliot WALDVOGEL
** File description:
** display.c
*/
#include "../include/my.h"

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

void radius_angle(infin_number_t *info)
{
    int x = 0;

    if (info->opt == 1)
        my_printf("Sphere ");
    else if (info->opt == 2)
        my_printf("Cylinder ");
    else {
        my_printf("Cone ");
        x = 1;
    }
    if (x == 0)
        my_printf("of radius %i\n", info->p);
    else
        my_printf("with a %i degree angle\n", info->p);
}

void line(infin_number_t *info)
{
    my_printf("Line passing through the point ");
    my_printf("(%i, %i, %i) ", info->xp, info->yp, info->zp);
    my_printf("and parallel to the vector ");
    my_printf("(%i, %i, %i)\n", info->xv, info->yv, info->zv);
}