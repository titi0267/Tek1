/*
** EPITECH PROJECT, 2020
** Scrolling_bakground by Timothy CONIEL
** File description:
** paralax.c
*/
#include "../include/my.h"

void init_text(menu_t *menu)
{
    menu->game_starting = 0;
    menu->random_move1 = 1;
    menu->random_move2 = 1;
    menu->delay = 0;
    menu->random = 0;
    menu->font_size = 80;
    menu->text_pos.y = 250;
    menu->text_pos.x = 100;
    menu->count_pos.x = 600;
    menu->count_pos.y = 200;
    menu->countdown = 3;
    menu->start_count = 0;
}

void init_background(background_t *back)
{
    back->position_back.x = 0;
    back->position_back.y = 0;
    back->pos_back.x = 1350;
    back->pos_back.y = 0;
}

void init_bottom(background_t *back)
{
    back->position_bott.x = 0;
    back->position_bott.y = 750;
    back->pos_bottom.x = 1350;
    back->pos_bottom.y = 750;
}

void init_timer(time_t *time)
{
    time->clock = sfClock_create();
    time->elapsed_time = 0;
    time->delta_time = 0;
}

int call_init(gather_t *gather, map_t *buff)
{
    init_timer(&gather->time);
    start_text(&gather->menu);
    //create_button(&gather->menu);
    bird_sprite(&gather->bird);
    create_sound(&gather->sound);
    if (pipe_sprite(&gather->enemy, buff, &gather->bird) != 0)
        return (-1);
    bottom(&gather->back);
    background(&gather->back);
    init_score(&gather->score);
    init_score_next(&gather->score);
    return (0);
}