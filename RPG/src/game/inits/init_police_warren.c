/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_police_warren
*/

#include "../../../include/func_name.h"

void init_policemen(rpg_t *rpg)
{
    sfTexture *police_gang = sfTexture_createFromFile
    ("assets/perso/policemen.png", NULL);

    rpg->game->in_game->objects->policemen = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->objects->policemen,
    police_gang, sfTrue);
}

static void init_rect_warren(rpg_t *rpg)
{
    rpg->game->in_game->objects->rect_warren.left = 0;
    rpg->game->in_game->objects->rect_warren.width = 65;
    rpg->game->in_game->objects->rect_warren.height = 100;
    rpg->game->in_game->objects->rect_warren.top = 0;
}

void init_warren(rpg_t *rpg)
{
    sfTexture *warren_gang = sfTexture_createFromFile
    ("assets/perso/warren.png", NULL);

    rpg->game->in_game->objects->warren = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->objects->warren,
    warren_gang, sfTrue);
    init_rect_warren(rpg);
}