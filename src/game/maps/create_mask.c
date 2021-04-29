/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto
*/

#include "../../../include/func_name.h"

void create_mask(rpg_t *rpg)
{
    sfColor color = sfSprite_getColor(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen]);
    if (collision(rpg, UP) == COLLISION) {
        sfImage_createMaskFromColor(rpg->game->in_game->map->maps
        [rpg->game->in_game->map->status], color, 0);
    }
}
