/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_other_maps
*/

#include "../../../include/func_name.h"

static void init_pos_warren(rpg_t *rpg)
{
    rpg->game->in_game->map->pos_map[MAP_WARREN] =
    put_in_vector2f(-1950, -1600);
    rpg->game->in_game->map->col_real[MAP_WARREN] =
    put_in_vector2u(930, 485);
}

static void init_inside_cdc(rpg_t *rpg)
{
    sfTexture *in_cdc = sfTexture_createFromFile
    ("assets/maps/real/cdc_int.png", NULL);

    rpg->game->in_game->map->collisions[MAP_INSIDE_CDC] =
    sfImage_createFromFile("assets/maps/colisions/cdc_int.png");
    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_INSIDE_CDC],
    in_cdc, sfTrue);
    rpg->game->in_game->map->tex_size_map[MAP_INSIDE_CDC] =
    sfTexture_getSize(in_cdc);
    rpg->game->in_game->map->pos_map[MAP_INSIDE_CDC] =
    put_in_vector2f(-1400, -2000);
    rpg->game->in_game->map->col_real[MAP_INSIDE_CDC] =
    put_in_vector2u(930, 485);
}

void init_cdc_map(rpg_t *rpg)
{
    sfTexture *out_cdc = sfTexture_createFromFile
    ("assets/maps/real/cdc_ext.png", NULL);

    rpg->game->in_game->map->collisions[MAP_OUTSIDE_CDC] =
    sfImage_createFromFile("assets/maps/colisions/cdc_ext.png");
    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_OUTSIDE_CDC],
    out_cdc, sfTrue);
    rpg->game->in_game->map->tex_size_map[MAP_OUTSIDE_CDC] =
    sfTexture_getSize(out_cdc);
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC] =
    put_in_vector2f(-100, -1400);
    rpg->game->in_game->map->col_real[MAP_OUTSIDE_CDC] =
    put_in_vector2u(930, 487);
    init_inside_cdc(rpg);
}

void init_disco_map(rpg_t *rpg)
{
    rpg->game->in_game->map->collisions[MAP_OUTSIDE_DISCO] =
    sfImage_createFromFile("assets/maps/colisions/disco_ext.png");
    sfTexture *out_disco = sfTexture_createFromFile
    ("assets/maps/real/disco_ext.png", NULL);

    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_OUTSIDE_DISCO],
    out_disco, sfTrue);
    rpg->game->in_game->map->tex_size_map[MAP_OUTSIDE_DISCO] =
    sfTexture_getSize(out_disco);
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO] =
    put_in_vector2f(-1200, -1600);
    rpg->game->in_game->map->col_real[MAP_OUTSIDE_DISCO] =
    put_in_vector2u(930, 487);
}

void init_warren_map(rpg_t *rpg)
{
    rpg->game->in_game->map->collisions[MAP_WARREN] =
    sfImage_createFromFile("assets/maps/colisions/warren_unblock.png");
    sfTexture *warren = sfTexture_createFromFile
    ("assets/maps/real/warren_unblock.png", NULL);

    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_WARREN],
    warren, sfTrue);
    rpg->game->in_game->map->tex_size_map[MAP_WARREN] =
    sfTexture_getSize(warren);
    init_pos_warren(rpg);
    init_cdc_map(rpg);
    init_disco_map(rpg);
}