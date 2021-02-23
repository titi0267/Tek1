/*
** EPITECH PROJECT, 2021
** Initialize all by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** init_regroup.c
*/

#include "../../include/defender.h"

void init(core_t *core)
{
    initialize_wnd(core->wnd);
    init_timer(core->time);
    mia(core->wnd);
    mia2(core->wnd);
}