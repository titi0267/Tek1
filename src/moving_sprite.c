/*
** EPITECH PROJECT, 2020
** moving sprite by Timothy CONIEL
** File description:
** moving_sprite.c
*/
#include "../include/my.h"

void update_time(time_t *time)
{
    time->delta_time = sfClock_restart(time->clock).microseconds / 1000000.0;
    time->elapsed_time += time->delta_time;
}

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

void updater(gather_t *gather)
{
    pipe_update(gather->windo.window, &gather->enemy);
    move_pipe_array(&gather->bird);
    bird_btw_pipe(&gather->bird);
    increase_score(&gather->score, gather->windo.window);
    bird_after_pipe(gather);
}

void bird_action(gather_t *gather)
{
    if (gather->bird.while_jump == 0)
        fall(&gather->bird, &gather->time);
    jump(&gather->bird);
    limit(&gather->enemy, &gather->bird);
    if (gather->bird.high == 0)
        gather->bird.death = 1;
}