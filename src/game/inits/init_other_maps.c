/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_other_maps
*/

#include "../../../include/func_name.h"

void init_pos_warren(rpg_t *rpg)
{
    rpg->game->in_game->map->pos_map[MAP_WARREN_BLOCK] =
    put_in_vector2f(-1950, -1600);
    rpg->game->in_game->map->pos_map[MAP_WARREN_NORMAL] =
    put_in_vector2f(-1850, -1800);
    rpg->game->in_game->map->col_real[MAP_WARREN_BLOCK] =
    put_in_vector2u(930, 485);
    rpg->game->in_game->map->col_real[MAP_WARREN_NORMAL] =
    put_in_vector2u(930, 485);
}

void init_warren_map(rpg_t *rpg)
{
    rpg->game->in_game->map->collisions[MAP_WARREN_BLOCK] =
    sfImage_createFromFile("assets/maps/colisions/warren_block.png");
    sfTexture *warren_block = sfTexture_createFromFile
    ("assets/maps/real/warren_block.png", NULL);
    rpg->game->in_game->map->collisions[MAP_WARREN_NORMAL] =
    sfImage_createFromFile("assets/maps/colisions/warren_unblock.png");
    sfTexture *warren_normal = sfTexture_createFromFile
    ("assets/maps/real/warren_unblock.png", NULL);

    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_WARREN_BLOCK],
    warren_block, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_WARREN_NORMAL],
    warren_normal, sfTrue);
    rpg->game->in_game->map->tex_size_map[MAP_WARREN_NORMAL] =
    sfTexture_getSize(warren_normal);
    rpg->game->in_game->map->tex_size_map[MAP_WARREN_BLOCK] =
    sfTexture_getSize(warren_block);
    init_pos_warren(rpg);
}