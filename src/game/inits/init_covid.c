/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_covid.c
*/

#include "../../../include/func_name.h"

void init_covid(rpg_t *rpg)
{
    sfTexture *vaccine_txt = sfTexture_createFromFile
    ("assets/inventory/vaccine.png", NULL);

    rpg->game->in_game->inventory->vaccine = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->inventory->vaccine, vaccine_txt,
    sfTrue);
    sfSprite_setPosition(rpg->game->in_game->inventory->vaccine,
    put_in_vector2f(370.5, 547.2));
}