/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void print_life(rpg_t *rpg)
{
    sfRectangleShape_setSize(rpg->game->in_game->stats->life,
    rpg->game->in_game->stats->life_size);
    sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->stats->life, NULL);
    sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->stats->life_border, NULL);
}