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
        rpg->game->in_game->map->pos_map[on_map].y += 3;
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        if (collision(rpg, UP) == COLLISION) {
            rpg->game->in_game->map->pos_map[on_map].y -= 3;
        }
        rect_move_player(rpg, UP);
        rpg->game->in_game->map->last_pos = UP;
    }
}

void move_down_map(rpg_t *rpg,int on_map)
{
    move_up_map(rpg, on_map);
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[DOWN]->text[0]) {
        rpg->game->in_game->map->pos_map[on_map].y -= 3;
        if (collision(rpg, DOWN) == COLLISION)
            rpg->game->in_game->map->pos_map[on_map].y += 3;
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
        rpg->game->in_game->map->pos_map[on_map].x -= 3;
        if (collision(rpg, RIGHT) == COLLISION) {
            rpg->game->in_game->map->pos_map[on_map].x += 3;
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
        rpg->game->in_game->map->pos_map[on_map].x += 3;
        if (collision(rpg, LEFT) == COLLISION) {
            rpg->game->in_game->map->pos_map[on_map].x -= 3;
        }
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, LEFT);
        rpg->game->in_game->map->last_pos = LEFT;
    }
}
