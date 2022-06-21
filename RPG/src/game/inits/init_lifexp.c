/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

static void init_life(rpg_t *rpg)
{
    rpg->game->in_game->stats->life_size = put_in_vector2f(400, 20);
    rpg->game->in_game->stats->life = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->game->in_game->stats->life,
    rpg->game->in_game->stats->life_size);
    sfRectangleShape_setFillColor(rpg->game->in_game->stats->life,
    sfColor_fromRGB(180, 0, 0));
    sfRectangleShape_setPosition(rpg->game->in_game->stats->life,
    put_in_vector2f(100, 50));
}

static void init_life_border(rpg_t *rpg)
{
    sfVector2f size = put_in_vector2f(400, 20);

    rpg->game->in_game->stats->life_border = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->game->in_game->stats->life_border, size);
    sfRectangleShape_setFillColor(rpg->game->in_game->stats->life_border,
    sfTransparent);
    sfRectangleShape_setOutlineColor(rpg->game->in_game->stats->life_border,
    sfColor_fromRGB(0, 54, 109));
    sfRectangleShape_setOutlineThickness(rpg->game->in_game->
    stats->life_border, 10);
    sfRectangleShape_setPosition(rpg->game->in_game->stats->life_border,
    put_in_vector2f(100, 50));
}

static void init_xp(rpg_t *rpg)
{
    rpg->game->in_game->stats->xp_size = put_in_vector2f(0, 20);
    rpg->game->in_game->stats->xp = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->game->in_game->stats->xp,
    rpg->game->in_game->stats->xp_size);
    sfRectangleShape_setFillColor(rpg->game->in_game->stats->xp,
    sfColor_fromRGB(95, 249, 254));
    sfRectangleShape_setPosition(rpg->game->in_game->stats->xp,
    put_in_vector2f(100, 100));
}

static void init_xp_border(rpg_t *rpg)
{
    sfVector2f size = put_in_vector2f(300, 20);

    rpg->game->in_game->stats->xp_border = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->game->in_game->stats->xp_border, size);
    sfRectangleShape_setFillColor(rpg->game->in_game->stats->xp_border,
    sfTransparent);
    sfRectangleShape_setOutlineColor(rpg->game->in_game->stats->xp_border,
    sfColor_fromRGB(0, 54, 109));
    sfRectangleShape_setOutlineThickness(rpg->game->in_game->
    stats->xp_border, 10);
    sfRectangleShape_setPosition(rpg->game->in_game->stats->xp_border,
    put_in_vector2f(100, 100));
}

void init_xplife(rpg_t *rpg)
{
    init_xp_border(rpg);
    init_life_border(rpg);
    init_life(rpg);
    init_xp(rpg);
}