/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** game_hitbox_next
*/

#include "../../../include/func_name.h"

void car_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x <=
    -2135 && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x >= -2409 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y <= -1310 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y >= -1761
    && rpg->game->in_game->phone->phone_status == 0) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        rpg->game->in_game->game_status = GM_NOTIF5;
    }
}

void warren_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_WARREN].x <=
    -363 && rpg->game->in_game->map->pos_map[MAP_WARREN].x >= -428 &&
    rpg->game->in_game->map->pos_map[MAP_WARREN].y <= -2724 &&
    rpg->game->in_game->map->pos_map[MAP_WARREN].y >= -2831
    && rpg->game->in_game->phone->phone_status == 0) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        sfSound_play(rpg->game->in_game->ig_sound->riley_warren);
        rpg->game->in_game->game_status = GM_RILEY_WARREN;
    }
}

void cdc_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_INSIDE_CDC
    && rpg->game->in_game->phone->phone_status == 0) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        rpg->game->in_game->game_status = GM_ELEVATOR;
    }
}