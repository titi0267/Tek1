/*
** EPITECH PROJECT, 2021
** police map inside
** File description:
** inside_police_station.c
*/

#include "../../../include/func_name.h"

static void police_texture_map(rpg_t *rpg)
{
    sfTexture *in_police = sfTexture_createFromFile
    ("assets/maps/real/police_int.png", NULL);
    rpg->game->in_game->map->collisions[MAP_INSIDE_POLICE] =
    sfImage_createFromFile("assets/maps/colisions/police_int.png");
    rpg->game->in_game->map->collisions[MAP_OUTSIDE_POLICE] =
    sfImage_createFromFile("assets/maps/colisions/police_ext.png");
    sfTexture *out_police = sfTexture_createFromFile
    ("assets/maps/real/police_ext.png", NULL);

    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_INSIDE_POLICE],
    in_police, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_OUTSIDE_POLICE],
    out_police, sfTrue);
    rpg->game->in_game->map->tex_size_map[MAP_INSIDE_POLICE] =
    sfTexture_getSize(in_police);
    rpg->game->in_game->map->tex_size_map[MAP_OUTSIDE_POLICE] =
    sfTexture_getSize(out_police);
    init_warren_map(rpg);
}

static void give_police_pos_map(rpg_t *rpg)
{
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE] =
    put_in_vector2f(-1265, -959);
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE] =
    put_in_vector2f(-1850, -1800);
    sfSprite_setPosition(rpg->game->in_game->map->maps[MAP_INSIDE_POLICE],
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE]);
    sfSprite_setPosition(rpg->game->in_game->map->maps[MAP_OUTSIDE_POLICE],
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE]);
    rpg->game->in_game->map->col_real[MAP_INSIDE_POLICE] =
    put_in_vector2u(930, 485);
    rpg->game->in_game->map->col_real[MAP_OUTSIDE_POLICE] =
    put_in_vector2u(930, 487);
    rpg->game->in_game->map->col_real[MAP_TUTO] = put_in_vector2u(660, 540);
}

int create_police_map(rpg_t *rpg)
{
    int map_nbr = 8;

    if ((rpg->game->in_game->map->maps = malloc(sizeof(sfSprite *) * map_nbr))
    == NULL || (rpg->game->in_game->map->collisions = malloc(sizeof(sfImage *)
    * map_nbr)) == NULL || (rpg->game->in_game->map->pos_map =
    malloc(sizeof(sfVector2f) * map_nbr)) == NULL ||
    (rpg->game->in_game->map->tex_size_map = malloc(sizeof(sfVector2u) *
    map_nbr)) == NULL || (rpg->game->in_game->map->col_real = malloc
    (sizeof(sfVector2u) * map_nbr)) == NULL)
        return (MALLOC_ERROR);
    for (int i = MAP_INSIDE_POLICE; i != NO_MAP; i++)
        rpg->game->in_game->map->maps[i] = sfSprite_create();
    police_texture_map(rpg);
    give_police_pos_map(rpg);
    init_map_tuto(rpg);
    return (set_key_color(rpg));
}

int set_key_color(rpg_t *rpg)
{
    if ((rpg->game->in_game->map->color = malloc(sizeof(sfColor) * 4)) == NULL)
        return (MALLOC_ERROR);
    rpg->game->in_game->map->color[COL] = sfImage_getPixel
    (rpg->game->in_game->map->collisions[MAP_INSIDE_POLICE], 4999, 4999);
    rpg->game->in_game->map->color[MASK] = sfImage_getPixel
    (rpg->game->in_game->map->collisions[MAP_TUTO], 0, 0);
    rpg->game->in_game->map->color[PASS] = sfImage_getPixel
    (rpg->game->in_game->map->collisions[MAP_OUTSIDE_POLICE], 0, 0);
    rpg->game->in_game->map->status = MAP_INSIDE_POLICE;
    return (0);
}