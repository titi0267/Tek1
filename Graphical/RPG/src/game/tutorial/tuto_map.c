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

void tuto_map(rpg_t *rpg)
{
    int on_map = rpg->game->in_game->map->status;

    move_left_map(rpg, on_map, rpg->game->in_game->objects,
    rpg->game->in_game->map);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->map->maps[on_map], NULL);
    if (rpg->tutorial->tutorial_stat >= 1)
        rect_move_car(rpg, rpg->game->in_game->objects,
        rpg->game->in_game->map->dir);
    if (rpg->game->in_game->objects->speed_status != CAR_SPEED)
        print_player_move_tuto(rpg);
}
