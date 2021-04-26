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
    sfTexture *map_col = sfTexture_createFromFile
    ("assets/tutorial/maps/col_tuto.png", NULL);
    sfVector2f pos = {0, -30};
    rpg->tutorial->map_pos = put_in_vector2f(-1809, -1027);

    rpg->tutorial->map_tuto = sfSprite_create();
    rpg->tutorial->map_tuto_col = sfSprite_create();
    sfSprite_setTexture(rpg->tutorial->map_tuto,
    map, sfTrue);
    sfSprite_setTexture(rpg->tutorial->map_tuto_col,
    map_col, sfTrue);
    sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
    sfSprite_setPosition(rpg->tutorial->map_tuto_col, rpg->tutorial->map_pos);
    for (int i = TUTO1; i != TUTO5; i++)
        sfSprite_setPosition(rpg->tutorial->instruct[i], pos);
}