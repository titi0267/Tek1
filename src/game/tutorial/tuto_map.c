/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto_map
*/

#include "../../../include/func_name.h"

void print_player_move_tuto(rpg_t *rpg)
{
    sfVector2f pos = {660, 540};

    sfSprite_setPosition(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen], pos);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen], NULL);
    stopped_moving(rpg);
}

void move_up_down_tuto_map(rpg_t *rpg)
{
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[UP]->text[0]) {
        rpg->tutorial->map_pos.y += 3;
        rpg->game->in_game->objects->car->car_pos.x += 3;
        sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
        rect_move_player(rpg, UP);
        rpg->game->in_game->map->last_pos = UP;
    }
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[DOWN]->text[0]) {
        rpg->tutorial->map_pos.y -= 3;
        rpg->game->in_game->objects->car->car_pos.x -= 3;
        sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
        rect_move_player(rpg, DOWN);
        rpg->game->in_game->map->last_pos = DOWN;
    }
}

void move_side_tuto_map(rpg_t *rpg)
{
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[LEFT]->text[0]) {
        rpg->tutorial->map_pos.x += 3;
        rpg->game->in_game->objects->car->car_pos.x += 3;
        sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
        rect_move_player(rpg, LEFT);
        rpg->game->in_game->map->last_pos = LEFT;
    }
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[RIGHT]->text[0]) {
        rpg->tutorial->map_pos.x -= 3;
        rpg->game->in_game->objects->car->car_pos.x -= 3;
        sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
        rect_move_player(rpg, RIGHT);
        rpg->game->in_game->map->last_pos = RIGHT;
    }
    move_up_down_tuto_map(rpg);
}

void tuto_map(rpg_t *rpg)
{
    int on_map = rpg->game->in_game->map->status;

    move_left_map(rpg, on_map);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->map->maps[on_map], NULL);
    print_player_move_tuto(rpg);
}
