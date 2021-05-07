/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void print_life(rpg_t *rpg)
{
    if (!on_cine(rpg)) {
        if (rpg->game->in_game->stats->player_stats[P_LIFE]->value < 0)
            rpg->game->in_game->stats->player_stats[P_LIFE]->value = 0;
        rpg->game->in_game->stats->life_size.x =
        (rpg->game->in_game->stats->player_stats[P_LIFE]->value * 400) / 100;
        sfRectangleShape_setSize(rpg->game->in_game->stats->life,
        rpg->game->in_game->stats->life_size);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->life, NULL);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->life_border, NULL);
    }
}

void print_xp(rpg_t *rpg)
{
    if (!on_cine(rpg)) {
        if (rpg->game->in_game->stats->xp_value >= 100) {
            rpg->game->in_game->stats->xp_value =
            rpg->game->in_game->stats->xp_value - 100;
            rpg->game->in_game->stats->player_stats[P_LIFE]->value = 100;
        }
        rpg->game->in_game->stats->xp_size.x =
        (rpg->game->in_game->stats->xp_value * 300) / 100;
        sfRectangleShape_setSize(rpg->game->in_game->stats->xp,
        rpg->game->in_game->stats->xp_size);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->xp, NULL);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->xp_border, NULL);
    }
}

void print_xp_life(rpg_t *rpg)
{
    print_xp(rpg);
    print_life(rpg);
}
