/*
** EPITECH PROJECT, 2021
** run
** File description:
** run
*/

#include "../../../include/func_name.h"

void player_run(rpg_t *rpg)
{
    static float nbr = 0;

    nbr += rpg->basic->cnf->clk->time_loop;
    if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[RUN]->text[0] &&
    nbr >= 0.2)) {
        rpg->game->in_game->objects->speed_status =
        (rpg->game->in_game->objects->speed_status == WALK_SPEED) ?
        RUN_SPEED : WALK_SPEED;
        nbr = 0;
    }
}