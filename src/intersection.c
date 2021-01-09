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

void arg_to_stru(infin_number_t *info, char **av)
{
    for (int i = 1; i <= 8; i++) {
        switch (i) {
            case 1:
                info->opt = my_getnbr(av[i]);
                break;
            case 2:
                info->xp = my_getnbr(av[i]);
                break;
            case 3:
                info->yp = my_getnbr(av[i]);
                break;
            case 4:
                info->zp = my_getnbr(av[i]);
                break;
            case 5:
                info->xv = my_getnbr(av[i]);
                break;
            case 6:
                info->yv = my_getnbr(av[i]);
                break;
            case 7:
                info->zv = my_getnbr(av[i]);
                break;
            case 8:
                info->p = my_getnbr(av[i]);
                break;
            default:
                break;
        }
    }
}

int which_form(gather_t *gather)
{
    if (gather->info->opt == 1) {
        if (find_inter_sph(gather->info, gather->sphere) == 84)
            return (84);
    }
    if (gather->info->opt == 2) {
        if (find_inter_cyl(gather->info, gather->cylindre) == 84)
            return (84);
    }
    return (0);
}

int intersection_core(gather_t *gather)
{
    radius_angle(gather->info);
    line(gather->info);
    if (which_form(gather) != 0)
        return (84);
    return (0);
}

int struct_malloc(gather_t *gather)
{
    gather->info = malloc(sizeof(infin_number_t));
    if (gather->info == NULL)
        return (84);
    gather->sphere = malloc(sizeof(sphere_t));
    if (gather->sphere == NULL)
        return (84);
    gather->cylindre = malloc(sizeof(cylindre_t));
    if (gather->cylindre == NULL)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    gather_t *gather = malloc(sizeof(gather_t));

    if (gather == NULL || struct_malloc(gather) == 84 || error_handling(ac, av) != 0) {
        return (84);
    }
    arg_to_stru(gather->info, av);
    if (null(gather->info) == 84)
        return (84);
    find_letters_cylindre(gather->info, gather->cylindre);
    if (intersection_core(gather) == 84)
        return (84);
    free(gather->cylindre);
    free(gather->sphere);
    free(gather->info);
    free(gather);
    return (0);
}