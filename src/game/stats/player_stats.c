/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void print_stats(rpg_t *rpg)
{
    for (int i = 0; i <= P_ARMOR; i++) {
        sfRenderWindow_drawText(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->player_stats[i]->txt, NULL);
    }
}