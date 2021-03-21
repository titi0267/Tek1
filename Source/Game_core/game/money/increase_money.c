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