/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** parsing_avance
*/

#include "../../../include/func_name.h"

void parsing_avance(rpg_t *rpg)
{
    chose_map(rpg);
    move_enemies(rpg);
    key_event_game(rpg);
    if (rpg->game->in_game->game_status == GM_BEGIN) {
        phone_main(rpg);
        desk_hitbox(rpg);
    }
    if (rpg->game->in_game->game_status == GM_SPEECH) {
        if (sfSound_getStatus(rpg->game->in_game->ig_sound->riley) == sfStopped)
            rpg->game->in_game->game_status = GM_NOTIF2;
    }
    if (rpg->game->in_game->game_status == GM_NOTIF2) {
        phone_main(rpg);
    }
}