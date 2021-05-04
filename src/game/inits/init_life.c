/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void init_life(rpg_t *rpg)
{
    rpg->game->in_game->stats->life_size = put_in_vector2f(400, 20);
    rpg->game->in_game->stats->life = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->game->in_game->stats->life,
    rpg->game->in_game->stats->life_size);
    sfRectangleShape_setFillColor(rpg->game->in_game->stats->life, sfColor_fromRGB(160, 0, 0));
    sfRectangleShape_setPosition(rpg->game->in_game->stats->life, put_in_vector2f(100, 100));
}

void init_life_border(rpg_t *rpg)
{
    sfVector2f pos = put_in_vector2f(400, 20);
    rpg->game->in_game->stats->life_border = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->game->in_game->stats->life_border, pos);
    sfRectangleShape_setFillColor(rpg->game->in_game->stats->life_border, sfTransparent);
    sfRectangleShape_setOutlineColor(rpg->game->in_game->stats->life_border, sfColor_fromRGB(0, 54, 109));
    sfRectangleShape_setOutlineThickness(rpg->game->in_game->stats->life_border, 10);
    sfRectangleShape_setPosition(rpg->game->in_game->stats->life, put_in_vector2f(100, 100));
}