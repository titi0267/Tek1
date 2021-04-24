/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_tuto_map
*/

#include "../../../include/func_name.h"

void init_map_tuto(rpg_t *rpg)
{
    sfTexture *map = sfTexture_createFromFile
    ("assets/tutorial/maps/map_tuto.png", NULL);

    rpg->tutorial->map_tuto = sfSprite_create();
    sfSprite_setTexture(rpg->tutorial->map_tuto,
    map, sfTrue);
}