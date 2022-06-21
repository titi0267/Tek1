/*
** EPITECH PROJECT, 2021
** knife
** File description:
** knife
*/
#include "../../../include/func_name.h"

void init_knife(rpg_t *rpg)
{
    sfTexture *text =
    sfTexture_createFromFile("assets/inventory/knife_anime.png", NULL);

    rpg->game->in_game->objects->knife = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->objects->knife, text, sfTrue);
}