/*
** EPITECH PROJECT, 2021
** chose map
** File description:
** map_status.c
*/

#include "../../../include/func_name.h"

void print_map(rpg_t *rpg, int on_map)
{
    move_left_map(rpg, on_map);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->map->maps[on_map], NULL);
    if (rpg->game->in_game->objects->player_incar == FALSE)
        print_player_move(rpg);
}

void chose_map(rpg_t *rpg)
{
    if (rpg->menu->status == ON_GAME) {
        rpg->game->in_game->map->status = MAP_INSIDE_POLICE;
        print_map(rpg, rpg->game->in_game->map->status);
    }
}

