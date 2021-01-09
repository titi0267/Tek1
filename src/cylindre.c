/*
** EPITECH PROJECT, 2021
** cylindre by Timothy CONIEL & Eliot WALDVOGEL
** File description:
** cylindre.c
*/
#include "../include/my.h"

void find_letters_cylindre(infin_number_t *info, cylindre_t *cylindre)
{
    cylindre->ax = pow(info->xv, 2);
    cylindre->bx = (2 * info->xp * info->xv);
    cylindre->cx = pow(info->xp, 2);
    cylindre->ay = pow(info->yv, 2);
    cylindre->by = (2 * info->yp * info->yv);
    cylindre->cy = pow(info->yp, 2);
    cylindre->a = cylindre->ax + cylindre->ay;
    cylindre->b = cylindre->bx + cylindre->by;
    cylindre->c = cylindre->cx + cylindre->cy - pow(info->p, 2);
}

int delta_cyl_is(infin_number_t *info , cylindre_t *cylindre)
{
    find_letters_cylindre(info, cylindre);
    cylindre->delta = pow(cylindre->b, 2) - (4 * cylindre->a * cylindre->c);
    if (cylindre->a == 0) {
        my_printf("There is an infinite number of intersection points.\n");
        return (1);
    }
    if (cylindre->delta < 0) {
        my_printf("No intersection point.\n");
        return (1);
    }
    if (cylindre->delta == 0) {
        my_printf("1 intersection point:\n");
        return (2);
    }
    if (cylindre->delta > 0) {
        my_printf("2 intersection points:\n");
        return (3);
    }
    return (0);
}

int solution_cyl(infin_number_t *info, cylindre_t *cylindre)
{
    int x = delta_cyl_is(info, cylindre);

    if (x == 84)
        return (84);
    if (x == 2) {
        cylindre->solution1 = ((float)-cylindre->b) / (2 * (float)cylindre->a);
        return (2);
    }
    if (x == 3) {
        cylindre->solution1 = ((float)-cylindre->b + sqrt(cylindre->delta)) / (2 * (float)cylindre->a);
        cylindre->solution2 = ((float)-cylindre->b - sqrt(cylindre->delta)) / (2 * (float)cylindre->a);
        return (3);
    }
    return (0);
}

int find_inter_cyl(infin_number_t *info, cylindre_t *cylindre)
{
    int x = solution_cyl(info, cylindre);

    if (x == 84)
        return (84);
    if (x == 2) {
        cylindre->x = info->xp + info->xv * cylindre->solution1;
        cylindre->y = info->yp + info->yv * cylindre->solution1;
        cylindre->z = info->zp + info->zv * cylindre->solution1;
        printf("(%2.3f, %2.3f, %2.3f)\n", cylindre->x, cylindre->y, cylindre->z);
    }
    if (x == 3) {
        cylindre->x = info->xp + info->xv * cylindre->solution1;
        cylindre->y = info->yp + info->yv * cylindre->solution1;
        cylindre->z = info->zp + info->zv * cylindre->solution1;
        cylindre->x1 = info->xp + info->xv * cylindre->solution2;
        cylindre->y1 = info->yp + info->yv * cylindre->solution2;
        cylindre->z1 = info->zp + info->zv * cylindre->solution2;
        printf("(%2.3f, %2.3f, %2.3f)\n", cylindre->x, cylindre->y, cylindre->z);
        printf("(%2.3f, %2.3f, %2.3f)\n", cylindre->x1, cylindre->y1, cylindre->z1);
    }
    return (0);
}
