/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** game_hitbox
*/

#include "../../../include/func_name.h"

void button_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x <=
    -1980 && rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x >= -2006
    && rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y <= -1220 &&
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y >= -1283
    && rpg->game->in_game->phone->phone_status == 0) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        rpg->game->in_game->game_status = GM_NOTIF4;
    }
}

void desk_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x <=
    -1770 && rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x >= -1810
    && rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y <= -710 &&
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y >= -730 &&
    rpg->game->in_game->phone->notif_index == 1 &&
    rpg->game->in_game->phone->phone_status == 0) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        sfSound_play(rpg->game->in_game->ig_sound->riley);
        rpg->game->in_game->game_status = GM_SPEECH;
    }
}

void notif2_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->phone->notif_index !=
    rpg->game->in_game->phone->notif_prev &&
    rpg->game->in_game->phone->phone_status == 0) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        rpg->game->in_game->game_status = GM_INCOMMING_CALL;
    }
}

void call_hitbox(rpg_t *rpg)
{
    if ((rpg->game->in_game->phone->phone_status == 2) &&
    (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1698)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 691)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1780)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 773))) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        rpg->game->in_game->game_status = GM_CALL;
        rpg->game->in_game->phone->notif_index++;
        sfSound_play(rpg->game->in_game->ig_sound->riley_call);
    }
}

void incall_hitbox(rpg_t *rpg)
{
    if ((rpg->game->in_game->phone->phone_status == 2) &&
    (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1600.5)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 688.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1686.5)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 774.5)))
        sfSound_stop(rpg->game->in_game->ig_sound->riley_call);
    if (sfSound_getStatus(rpg->game->in_game->ig_sound->riley_call) ==
    sfStopped) {
        rpg->game->in_game->game_status = GM_NOTIF3;
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        rpg->game->in_game->phone->phone_status = 0;
    }
}