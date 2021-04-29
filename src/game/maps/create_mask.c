/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto
*/

#include "../../../include/func_name.h"

 get_spt_color(rpg_t *rpg)
{
    color = sfImage_getPixel(rpg->game->in_game->map->collisions
    [MAP_TUTO], 0, 0);
}

void create_mask(rpg_t *rpg)
{
    sfColor color = sfSprite_getColor(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen]);
    color_mask = sfImage_getPixel(rpg->game->in_game->map->collisions
    [MAP_TUTO], 0, 0);
    if (collision(rpg, UP) == COLLISION) {
        sfImage_createMaskFromColor(rpg->game->in_game->map->maps
        [rpg->game->in_game->map->status], color, 0);
    }
}
