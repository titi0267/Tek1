/*
** EPITECH PROJECT, 2021
** malloc by Timothy CONIEL & Trista HOURTOUILLE
** File description:
** malloc.c
*/

#include "../../include/defender.h"

int struct_alloc(core_t *core)
{
    core->wnd = malloc(sizeof(window_t));
    core->time = malloc(sizeof(time_t));

    if (core == NULL || core->wnd == NULL || core->time == NULL)
        return (ERROR);
    return (0);
}
