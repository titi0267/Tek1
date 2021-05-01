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
    rpg->game->in_game->map->status = MAP_OUTSIDE_POLICE;
}

void choose_map_outside_police(rpg_t *rpg)
{
    printf("Change x = %f & y = %f\n", rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x, rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y);
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x > 200 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y < -1500) {
        printf("WARREN\n");
        rpg->game->in_game->map->status = MAP_WARREN_BLOCK;
    }
    //x = 280 & y = -1860
}

void change_map(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_TUTO) {
        rpg->menu->status = ON_MENU;
        rpg->game->in_game->map->status = MAP_INSIDE_POLICE;
    }
    if (rpg->game->in_game->map->status == MAP_INSIDE_POLICE)
        place_outside_police(rpg);
    if (rpg->game->in_game->map->status == MAP_OUTSIDE_POLICE)
        choose_map_outside_police(rpg);
}