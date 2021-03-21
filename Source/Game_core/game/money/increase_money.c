/*
** EPITECH PROJECT, 2021
** increase money by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** increase_money.c
*/

#include "../../../../include/defender.h"

void eco_placed(core_t *core)
{
    static float nbr = 0;

    nbr += core->time->delta_time;
    if (core->game->tower->eco_placed == TRUE && nbr > 5) {
        core->game->money++;
        nbr = 0;
    }
}

void buy(core_t *core)
{
    if ((core->game->tower->wich_defense == ice_tower)
            && (core->game->money - 5) >= 0) {
        core->game->money -= 5;
        core->game->accpet = TRUE;
    } else if ((core->game->tower->wich_defense == wiz_tower)
    && (core->game->money - 10) >= 0) {
        core->game->money -= 10;
        core->game->accpet = TRUE;
    }
    if ((core->game->tower->wich_defense == arrow_tower)
        && (core->game->money - 15) >= 0) {
        core->game->money -= 15;
        core->game->accpet = TRUE;
    } else if ((core->game->tower->wich_defense == eco_center)
        && (core->game->money - 20) >= 0) {
        core->game->money -= 20;
        core->game->accpet = TRUE;
    }
}

void block_buy(core_t *core)
{
    if (core->game->money < 5)
        core->game->tower->wich_defense = poor;
    else if (core->game->money >= 5)
        buy(core);
    else
        core->game->tower->wich_defense = poor;
}