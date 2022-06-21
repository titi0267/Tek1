/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** hitbox_loot
*/

#include "../../../include/func_name.h"

void weapon_hitbox2(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].x <=
    -704 && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].x >= -779
    && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].y <= -2268 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].y >= -2343) {
        rpg->game->in_game->stuff->stuff_status[SMG] = TRUE;
    }
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].x <=
    -728 && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].x >= -803
    && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].y <= -2124 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].y >= -2199) {
        rpg->game->in_game->stuff->stuff_status[TAZER] = TRUE;
    }
}

void weapon_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x <=
    -784 && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x >= -860
    && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y <= -2844 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y >= -2920) {
        rpg->game->in_game->stuff->stuff_status[GUN] = TRUE;
    }
    if (rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x <=
    -1105 && rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x >= -1181
    && rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y <= -1475 &&
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y >= -1551) {
        rpg->game->in_game->stuff->stuff_status[KNIFE] = TRUE;
    }
}

void vest_hitbox(rpg_t *rpg)
{
    if ((rpg->game->in_game->map->pos_map[MAP_WARREN].x <=
    -1388 && rpg->game->in_game->map->pos_map[MAP_WARREN].x >= -1463
    && rpg->game->in_game->map->pos_map[MAP_WARREN].y <= -1922 &&
    rpg->game->in_game->map->pos_map[MAP_WARREN].y >= -1997) ||
    rpg->game->in_game->stuff->stuff_status[BPVEST] == TRUE) {
        rpg->game->in_game->stuff->stuff_status[BPVEST] = TRUE;
        rpg->game->in_game->inventory->pos_weapon[BPVEST].x =
        rpg->game->in_game->inventory->box_pos[17][0].x;
        rpg->game->in_game->inventory->pos_weapon[BPVEST].y =
        rpg->game->in_game->inventory->box_pos[17][0].y;
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[BPVEST],
        rpg->game->in_game->inventory->pos_weapon[BPVEST]);
        rpg->game->in_game->inventory->area_contains[VEST] = TRUE;
    }
}
