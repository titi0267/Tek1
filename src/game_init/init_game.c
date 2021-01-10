/*
** EPITECH PROJECT, 2020
** Scrolling_bakground by Timothy CONIEL
** File description:
** paralax.c
*/
#include "../../include/my.h"

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
    menu->stop_game = 0;
    menu->change_button = 0;
    menu->restart = 0;
}

void init_static(enemy_t *enemy, player_t *bird)
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
    init_static(&gather->enemy, &gather->bird);
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
    init_score_next(&gather->score);
    game_over(&gather->menu);
    return (0);
}

int init_enemy(enemy_t *enemy, map_t *buff, player_t *bird)
{
    buff->char_val = 0;
    buff->lin_val = 0;
    for (; buff->lin_val != 11; buff->lin_val++) {
        for (; buff->line[buff->lin_val][buff->char_val] != '\0';
            buff->char_val++) {
            space_btw_pipe(enemy, buff);
            if (buff->line[buff->lin_val][buff->char_val] ==
                ' ' && (buff->char_val % 8) == 0)
                fill_array(enemy, bird);
            place_obstacles(enemy, buff);
            place_obstacles_next(enemy, buff);
        }
        buff->char_val = 0;
    }
    return (0);
}

void reset_static(enemy_t *enemy, player_t *bird)
{
    enemy->pos_di = 0;
    enemy->pos_x = 0;
    enemy->pos_uf = 0;
    bird->col_arr = 1;
    enemy->death_i = 0;
    bird->move_pipe = 1;
    enemy->fill_d = 0;
    bird->aft_pip = 1;
    for (int h = 0; h < 18; h++)
        bird->collision[h].x = 0;
    bird->angle = 0;
    bird->rotate_speed = 1;
}

void re_init(gather_t *gather, map_t *buff)
{
    reset_static(&gather->enemy, &gather->bird);
    init_text(&gather->menu);
    init_button(&gather->menu);
    bird_init(&gather->bird);
    init_enemy(&gather->enemy, buff, &gather->bird);
    init_bottom(&gather->back);
    init_background(&gather->back);
    reset_score(&gather->score);
}