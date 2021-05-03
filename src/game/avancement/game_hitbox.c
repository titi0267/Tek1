/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** game_hitbox
*/

#include "../../../include/func_name.h"

// -1754 -727
// -1828 -754

void desk_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x <=
    -1770 && rpg->game->in_game->map->pos_map[rpg->game->in_game->
    map->status].x >= -1810 && rpg->game->in_game->map->pos_map[rpg->game->
    in_game->map->status].y <= -710 && rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y >= -730 &&
    rpg->game->in_game->phone->notif_index == 1) {
        rpg->game->in_game->game_status = GM_SPEECH;
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        sfSound_play(rpg->game->in_game->ig_sound->riley);
    }
}