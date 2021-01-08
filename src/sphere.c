/*
** EPITECH PROJECT, 2021
** line by Timothy CONIEL & Eliot WALDVOGEL
** File description:
** line.c
*/
#include "../include/my.h"

void line(char **av, infin_number_t *info)
{
    my_printf("Line passing through the point ");
    my_printf("(%i, %i, %i) ", info->xp, info->yp, info->zp);
    my_printf("and parallel to the vector ");
    my_printf("(%i, %i, %i)\n", info->xv, info->yv, info->zv);
}

int find_letters(infin_number_t *info, sphere_t *sphere)
{
    sphere->ax = info->xv;
    sphere->bx = (2 * info->xp * info->xv);
    sphere->cx = info->xp;
    sphere->ay = info->yv;
    sphere->by = (2 * info->yp * info->yv);
    sphere->cy = info->yp;
    sphere->az = info->zv;
    sphere->bz = (2 * info->zp * info->zv);
    sphere->cz = info->zp;
    sphere->a = sphere->ax + sphere->ay + sphere->az;
    sphere->b = sphere->bx + sphere->by + sphere->bz;
    sphere->c = sphere->cx + sphere->cy + sphere->cz - info->p;
    sphere->a = pow(sphere->a, 2);
    sphere->c = pow(sphere->c, 2);
    if (divide_0(info, sphere) == 84)
        return (84);
    return (0);
}

void sphere_equation(infin_number_t *info, sphere_t *sphere)
{
    sphere->ax = pow(info->xv, 2);
    sphere->bx = pow((2 * info->xp * info->xv), 2);
    sphere->cx = pow(info->xp, 2);
    sphere->ay = pow(info->yv, 2);
    sphere->by = pow((2 * info->yp * info->yv), 2);
    sphere->cy = pow(info->yp, 2);
    sphere->az = pow(info->zv, 2);
    sphere->bz = pow((2 * info->zp * info->zv), 2);
    sphere->cz = pow(info->zp, 2);
    sphere->a_sqrt = sphere->ax + sphere->ay + sphere->az;
    sphere->b_sqrt = sphere->bx + sphere->by + sphere->bz;
    sphere->c_sqrt = (sphere->cx + sphere->cy + sphere->cz) - pow(info->p, 2);
    sphere->delta = sphere->b_sqrt - (4 * sphere->a_sqrt * sphere->c_sqrt);
}

int delta_is(infin_number_t *info , sphere_t *sphere)
{
    sphere_equation(info, sphere);
    if (sphere->delta < 0) {
        my_printf("No intersection point.\n");
        return (1);
    }
    if (sphere->delta == 0) {
        my_printf("1 intersection point:\n");
        return (2);
    }
    if (sphere->delta > 0) {
        my_printf("2 intersection points:\n");
        return (3);
    }
    return (0);
}

int solution(infin_number_t *info, sphere_t *sphere)
{
    int x = delta_is(info, sphere);

    if (find_letters(info, sphere) == 84)
        return (84);
    if (x == 84)
        return (84);
    if (x == 1)
        return (1);
    if (x == 2) {
        sphere->solution1 = ((float)-sphere->b) / (2 * (float)sphere->a);
        return (2);
    }
    if (x == 3) {
        sphere->solution1 = ((float)-sphere->b + sqrt(sphere->delta)) / (2 * (float)sphere->a);
        sphere->solution2 = ((float)-sphere->b - sqrt(sphere->delta)) / (2 * (float)sphere->a);
        return (3);
    }
    return (0);
}

int find_inter(infin_number_t *info, sphere_t *sphere)
{
    int x = solution(info, sphere);

    if (x == 84)
        return (84);
    if (x == 2) {
        sphere->x = info->xp + info->xv * sphere->solution1;
        sphere->y = info->yp + info->yv * sphere->solution1;
        sphere->z = info->zp + info->zv * sphere->solution1;
        printf("(%2.3f, %2.3f, %2.3f)\n", sphere->x, sphere->y, sphere->z);
    }
    if (x == 3) {
        sphere->x = info->xp + info->xv * sphere->solution1;
        sphere->y = info->yp + info->yv * sphere->solution1;
        sphere->z = info->zp + info->zv * sphere->solution1;
        sphere->x1 = info->xp + info->xv * sphere->solution2;
        sphere->y1 = info->yp + info->yv * sphere->solution2;
        sphere->z1 = info->zp + info->zv * sphere->solution2;
        printf("(%2.3f, %2.3f, %2.3f)\n", sphere->x, sphere->y, sphere->z);
        printf("(%2.3f, %2.3f, %2.3f)\n", sphere->x1, sphere->y1, sphere->z1);
    }
    return (0);
}