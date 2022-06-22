/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** reset_inventory
*/

#include "../../../include/func_name.h"

void reset_inventory(rpg_t *rpg)
{
    for (int i = SMG; i < NO_WEAPON; i++)
        rpg->game->in_game->stuff->stuff_status[i] = FALSE;
    rpg->game->in_game->stuff->stuff_status[BPVEST] = FALSE;
    rpg->game->in_game->inventory->is_area_filled[WEAPON] = FALSE;
    rpg->game->in_game->inventory->is_area_filled[AMMO] = FALSE;
    rpg->game->in_game->inventory->is_area_filled[VEST] = FALSE;
    rpg->game->in_game->inventory->area_contains[WEAPON] = NO_WEAPON;
    rpg->game->in_game->inventory->area_contains[AMMO] = NO_BULLET;
    rpg->game->in_game->inventory->area_contains[VEST] = NO_VEST;
    rpg->game->in_game->inventory->vaccine_status = FALSE;
    init_stuff(rpg);
    rpg->game->end->status_cinematic2 = FALSE;
}