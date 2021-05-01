/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** switch_map
*/

#include "../../../include/func_name.h"

void place_outside_police(rpg_t *rpg)
{
    printf("OUTSIDE\n");
    sfSprite_setPosition(rpg->game->in_game->map->maps[MAP_OUTSIDE_POLICE], put_in_vector2f(-1200, -700));
    rpg->game->in_game->map->status = MAP_OUTSIDE_POLICE;
}

void change_map(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_TUTO)
        rpg->menu->status = ON_MENU;
    if (rpg->game->in_game->map->status == MAP_INSIDE_POLICE)
        place_outside_police(rpg);
}