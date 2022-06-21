/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void init_levelup_stat(rpg_t *rpg)
{
    sfTexture *text = sfTexture_createFromFile
    ("assets/inventory/increment.png", NULL);

    rpg->game->in_game->inventory->add_damage = sfSprite_create();
    rpg->game->in_game->inventory->add_armor = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->inventory->add_damage,
    text, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->inventory->add_armor, text, sfTrue);
    sfSprite_setPosition(rpg->game->in_game->inventory->add_damage,
    put_in_vector2f(1527.1, 558.5));
    sfSprite_setPosition(rpg->game->in_game->inventory->add_armor,
    put_in_vector2f(1527.1, 665));
    rpg->game->in_game->inventory->level_up_text = sfText_create();
    sfText_setFont(rpg->game->in_game->inventory->level_up_text,
    sfFont_createFromFile("assets/fonts/aqua.ttf"));
    sfText_setCharacterSize(rpg->game->in_game->inventory->level_up_text, 20);
    sfText_setPosition(rpg->game->in_game->inventory->level_up_text,
    put_in_vector2f(1127.1, 750));
}