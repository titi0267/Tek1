/*
** EPITECH PROJECT, 2021
** chose map
** File description:
** map_status.c
*/

#include "../../../include/func_name.h"

void print_map(rpg_t *rpg, int on_map)
{
    if (rpg->menu->status == ON_GAME &&
    !on_cine(rpg)) {
        player_run(rpg);
        move_left_map(rpg, on_map);
    }
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->map->maps[on_map], NULL);
    print_player_move(rpg);
    //move_enemies(rpg);
}

void chose_map(rpg_t *rpg)
{
    print_map(rpg, rpg->game->in_game->map->status);
}