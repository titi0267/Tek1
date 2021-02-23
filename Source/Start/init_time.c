/*
** EPITECH PROJECT, 2021
** initialize time by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** init_time.c
*/

#include "../../include/defender.h"

void init_timer(time_t *time)
{
    time->clock = sfClock_create();
    time->elapsed_time = 0;
    time->delta_time = 0;
}
