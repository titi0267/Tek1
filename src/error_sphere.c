/*
** EPITECH PROJECT, 2021
** error_sphere by Timothy CONIEL & Eliot WALDVOGEL
** File description:
** error_sphere.c
*/
#include "../include/my.h"

int divide_0(infin_number_t *info, sphere_t *sphere)
{
    if (sphere->a == 0) {
        my_printf("ERROR: Cannot divide by 0, no intersecion points\n");
        return (84);
    }
    return (0);
}