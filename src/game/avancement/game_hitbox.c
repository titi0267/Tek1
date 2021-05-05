/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** game_hitbox
*/

#include "../../../include/func_name.h"

// -2006 x -1283

void button_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x <=
    -1980 && rpg->game->in_game->map->pos_map[rpg->game->in_game->
    map->status].x >= -2006 && rpg->game->in_game->map->pos_map[rpg->game->
    in_game->map->status].y <= -1220 &&
    rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].y >= -1283
    && rpg->game->in_game->phone->phone_status == 0) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        rpg->game->in_game->game_status = GM_NOTIF4;
    }
}

void desk_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x <=
    -1770 && rpg->game->in_game->map->pos_map[rpg->game->in_game->
    map->status].x >= -1810 && rpg->game->in_game->map->pos_map[rpg->game->
    in_game->map->status].y <= -710 && rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y >= -730 &&
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
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1731)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 688.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1778.5)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 774.5))) {
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