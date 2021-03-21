/*
** EPITECH PROJECT, 2021
** timer by TImothy CONIEL & Tristan HOURTOUILLE
** File description:
** timer.c
*/

#include "../../include/defender.h"

void update_time(core_t *core)
{
    if (core->menu->pause_on == FALSE) {
        if (core->time->recreate_clock == TRUE) {
            core->time->clock = sfClock_create();
            core->time->delta_time = 0;
            core->time->recreate_clock = FALSE;
        }
        core->time->delta_time = sfClock_restart(core->time->clock).microseconds / 1000000.0;
        core->time->elapsed_time += core->time->delta_time;
    } else if (core->menu->pause_on == TRUE && core->time->recreate_clock == FALSE) {
        sfClock_destroy(core->time->clock);
        core->time->recreate_clock = TRUE;
    }
}
