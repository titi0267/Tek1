/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** actions_tuto
*/

#include "../../../include/func_name.h"

void end_tuto(rpg_t *rpg)
{
    sfVector2f tutorial_pos =
    sfSprite_getPosition(rpg->game->in_game->map->collisions[MAP_TUTO]);

    if (((tutorial_pos.x) >= adapt_x(rpg, -3703)) &&
    ((tutorial_pos.y) >= adapt_y(rpg, -3118))) {
        
    }
}