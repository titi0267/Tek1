/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void update_damage(rpg_t *rpg)
{
    switch (rpg->game->in_game->inventory->area_contains[WEAPON]) {
        case KNIFE:
            rpg->game->in_game->stats->player_stats[P_DAMAGE]->value = 50;
            break;
        case SMG:
            rpg->game->in_game->stats->player_stats[P_DAMAGE]->value = 25;
            break;
        case GUN:
            rpg->game->in_game->stats->player_stats[P_DAMAGE]->value = 15;
            break;
        case TAZER:
            rpg->game->in_game->stats->player_stats[P_DAMAGE]->value = 35;
            break;
        default:
            rpg->game->in_game->stats->player_stats[P_DAMAGE]->value = 5;
            break;
    }
}

void update_invent_stats(rpg_t *rpg)
{
    update_damage(rpg);
    for (int i = 0; i <= P_ARMOR; i++) {
        sfText_setString(rpg->game->in_game->stats->player_stats[i]->txt,
        my_putnbr(rpg->game->in_game->stats->player_stats[i]->value));
    }
}

void print_stats(rpg_t *rpg)
{
    for (int i = 0; i <= P_ARMOR; i++) {
        update_invent_stats(rpg);
        sfRenderWindow_drawText(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->player_stats[i]->txt, NULL);
    }
}
