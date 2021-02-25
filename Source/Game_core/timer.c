/*
** EPITECH PROJECT, 2021
** timer by TImothy CONIEL & Tristan HOURTOUILLE
** File description:
** timer.c
*/

#include "../../include/defender.h"

void update_time(time_t *time)
{
    time->delta_time = sfClock_restart(time->clock).microseconds / 1000000.0;
    time->elapsed_time += time->delta_time;
}
