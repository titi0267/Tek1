/*
** EPITECH PROJECT, 2021
** different directions
** File description:
** directions.c
*/

#include "../../../include/func_name.h"

void move_up_map(rpg_t *rpg, int on_map, objects_t *objects, map_t *map)
{
    if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[UP]->text[0])) {
        if (check_collision(rpg, UP) != COLLISION) {
            map->pos_map[on_map].y += map->speed[objects->speed_status];
            if (map->speed[objects->speed_status] != 5 && map->status
            == MAP_TUTO)
                objects->car->car_pos_tuto.y +=
                map->speed[objects->speed_status];
            else if (map->speed[objects->speed_status] != 5
            && map->status != MAP_TUTO && map->draw_car != FALSE) {
                objects->car->car_pos.y +=
                map->speed[objects->speed_status];
            }
            move_enemies_on_map(rpg, UP);
            map->dir = UP;
        }
        sfSprite_setPosition(map->maps[on_map], map->pos_map[on_map]);
        rect_move_player(rpg, UP);
        map->last_pos = UP;
    }
}

void move_down_map(rpg_t *rpg, int on_map, objects_t *objects, map_t *map)
{
    move_up_map(rpg, on_map, objects, map);
    if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[DOWN]->text[0])) {
        if (check_collision(rpg, DOWN) != COLLISION) {
            map->pos_map[on_map].y -= map->speed[objects->speed_status];
            if (map->speed[objects->speed_status] != 5 &&
            map->status == MAP_TUTO)
                objects->car->car_pos_tuto.y -=
                map->speed[objects->speed_status];
            else if (map->speed[objects->speed_status] != 5
            && map->status != MAP_TUTO && map->draw_car != FALSE) {
                objects->car->car_pos.y -= map->speed[objects->speed_status];
            }
            move_enemies_on_map(rpg, DOWN);
            map->dir = DOWN;
        }
        sfSprite_setPosition(map->maps[on_map], map->pos_map[on_map]);
        rect_move_player(rpg, DOWN);
        map->last_pos = DOWN;
    }
}

void move_right_map(rpg_t *rpg, int on_map, objects_t *objects, map_t *map)
{
    move_down_map(rpg, on_map, objects, map);
    if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[RIGHT]->text[0])) {
        if (check_collision(rpg, RIGHT) != COLLISION) {
            map->pos_map[on_map].x -= map->speed[objects->speed_status];
            if (map->speed[objects->speed_status] != 5 &&
                map->status == MAP_TUTO)
                objects->car->car_pos_tuto.x -=
                map->speed[objects->speed_status];
            else if (map->speed[objects->speed_status] != 5 &&
            map->status != MAP_TUTO && map->draw_car != FALSE)
                objects->car->car_pos.x -= map->speed[objects->speed_status];
            move_enemies_on_map(rpg, RIGHT);
            map->dir = RIGHT;
        }
        sfSprite_setPosition(map->maps[on_map], map->pos_map[on_map]);
        rect_move_player(rpg, RIGHT);
        map->last_pos = RIGHT;
    }
}

void move_left_map(rpg_t *rpg, int on_map, objects_t *objects, map_t *map)
{
    move_right_map(rpg, on_map, objects, map);
    if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[LEFT]->text[0])) {
        if (check_collision(rpg, LEFT) != COLLISION) {
            map->pos_map[on_map].x += map->speed[objects->speed_status];
            if (map->speed[objects->speed_status] != 5 &&
            map->status == MAP_TUTO)
                objects->car->car_pos_tuto.x +=
                map->speed[objects->speed_status];
            else if (map->speed[objects->speed_status] != 5 &&
            map->status != MAP_TUTO && map->draw_car != FALSE)
                objects->car->car_pos.x += map->speed[objects->speed_status];
            move_enemies_on_map(rpg, LEFT);
            map->dir = LEFT;
        }
        sfSprite_setPosition(map->maps[on_map],
        map->pos_map[on_map]);
        rect_move_player(rpg, LEFT);
        map->last_pos = LEFT;
    }
}

void player_stop(rpg_t *rpg)
{
    if (rpg->game->in_game->map->last_pos != -1) {
        rpg->menu->main_menu->new_game->char_in_game
        [rpg->game->in_game->map->last_pos].left = 100;
        rpg->game->in_game->map->dir = 5;
        if (rpg->game->in_game->stuff->stuff_status[BPVEST] == FALSE)
            sfSprite_setTextureRect(rpg->game->in_game->objects->players[rpg->
            menu->main_menu->new_game->character_chosen], rpg->menu->main_menu->
            new_game->char_in_game[rpg->game->in_game->map->last_pos]);
        else
            sfSprite_setTextureRect(rpg->game->in_game->objects->player_vest
            [rpg->menu->main_menu->new_game->character_chosen],
            rpg->menu->main_menu->new_game->char_in_game
            [rpg->game->in_game->map->last_pos]);
    }
    for (int d = 0; d != 4; d++) {
        rpg->menu->main_menu->new_game->char_in_game[d].left = 100;
        rpg->menu->main_menu->new_game->offset_character[d] = 0;
    }
}