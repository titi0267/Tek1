/*
** EPITECH PROJECT, 2020
** Scrolling_bakground by Timothy CONIEL
** File description:
** paralax.c
*/
#include "../../include/my.h"

void init_static(enemy_t *enemy, player_t *bird, sound_t *sound)
{
    enemy->pos_di = 0;
    enemy->pos_x = 0;
    enemy->fill_d = 0;
    bird->col_arr = 1;
    enemy->death_i = 0;
    bird->angle = 0;
    bird->rotate_speed = 1;
    enemy->pos_uf = 0;
    bird->move_pipe = 1;
    bird->aft_pip = 1;
    sound->played = 0;
}

void init_timer(time_t *time)
{
    time->clock = sfClock_create();
    time->elapsed_time = 0;
    time->delta_time = 0;
}

int call_init(gather_t *gather, map_t *buff)
{
    init_static(&gather->enemy, &gather->bird, &gather->sound);
    init_timer(&gather->time);
    start_text(&gather->menu);
    create_button(&gather->menu);
    create_button_black(&gather->menu);
    create_load(&gather->menu);
    bird_sprite(&gather->bird);
    create_sound(&gather->sound);
    if (pipe_sprite(&gather->enemy, buff, &gather->bird) != 0)
        return (-1);
    bottom(&gather->back);
    background(&gather->back);
    init_score(&gather->score);
    gather->score.max = 0;
    init_score_next(&gather->score);
    won(&gather->back);
    game_over(&gather->menu);
    return (0);
}
