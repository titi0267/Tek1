/*
** EPITECH PROJECT, 2021
** different directions
** File description:
** directions.c
*/

#include "../../../include/func_name.h"

void move_up_map(rpg_t *rpg, int on_map)
{
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[UP]->text[0]) {
        if (check_collision(rpg, UP) != COLLISION) {
            rpg->game->in_game->map->pos_map[on_map].y +=
            rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
            rpg->game->in_game->objects->car->car_pos.y +=
            rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
            move_enemies_on_map(rpg, UP);
        }
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, UP);
        rpg->game->in_game->map->last_pos = UP;
    }
}

void move_down_map(rpg_t *rpg,int on_map)
{
    move_up_map(rpg, on_map);
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[DOWN]->text[0]) {
        if (check_collision(rpg, DOWN) != COLLISION) {
            rpg->game->in_game->map->pos_map[on_map].y -=
            rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
            rpg->game->in_game->objects->car->car_pos.y -=
            rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
            move_enemies_on_map(rpg, DOWN);
        }
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, DOWN);
        rpg->game->in_game->map->last_pos = DOWN;
    }
}

void move_right_map(rpg_t *rpg, int on_map)
{
    move_down_map(rpg, on_map);
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[RIGHT]->text[0]) {
        if (check_collision(rpg, RIGHT) != COLLISION) {
            rpg->game->in_game->map->pos_map[on_map].x -=
            rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
            rpg->game->in_game->objects->car->car_pos.x -=
            rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
            move_enemies_on_map(rpg, RIGHT);
        }
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, RIGHT);
        rpg->game->in_game->map->last_pos = RIGHT;
    }
}

void move_left_map(rpg_t *rpg, int on_map)
{
    move_right_map(rpg, on_map);
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[LEFT]->text[0]) {
        if (check_collision(rpg, LEFT) != COLLISION) {
            rpg->game->in_game->map->pos_map[on_map].x +=
            rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
            rpg->game->in_game->objects->car->car_pos.x +=
            rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
            move_enemies_on_map(rpg, LEFT);
        }
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, LEFT);
        rpg->game->in_game->map->last_pos = LEFT;
    }
}

void player_stop(rpg_t *rpg)
{
    if (rpg->game->in_game->map->last_pos != -1) {
        rpg->menu->main_menu->new_game->char_in_game
        [rpg->game->in_game->map->last_pos].left = 100;
        sfSprite_setTextureRect(rpg->game->in_game->objects->players[rpg->
        menu->main_menu->new_game->character_chosen], rpg->menu->main_menu->
        new_game->char_in_game[rpg->game->in_game->map->last_pos]);
    }
    for (int d = 0; d != 4; d++) {
        rpg->menu->main_menu->new_game->char_in_game[d].left = 100;
        rpg->menu->main_menu->new_game->offset_character[d] = 0;
    }
}