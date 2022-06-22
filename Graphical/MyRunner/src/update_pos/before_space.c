/*
** EPITECH PROJECT, 2021
** before space by Timothy CONIEL
** File description:
** before_space.c
*/
#include "../../include/my.h"

void update_start(gather_t *gather)
{
    background_update(gather->windo.window, &gather->back);
    bottom_update(gather->windo.window, &gather->back);
    bird_update(&gather->bird, gather->windo.window);
    bird_anim_speed(&gather->time, &gather->bird);
    update_press(gather);
    if (gather->menu.start_count == 1 && gather->menu.countdown >= 0)
        update_count(gather);
}

void update_time(time_t *time)
{
    time->delta_time = sfClock_restart(time->clock).microseconds / 1000000.0;
    time->elapsed_time += time->delta_time;
}