/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** print_warren
*/

#include "../../../include/func_name.h"

void print_warren(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_WARREN &&
    (rpg->game->in_game->game_status == GM_NOTIF6 ||
    rpg->game->in_game->game_status == GM_RILEY_WARREN)) {
        sfSprite_setPosition(rpg->game->in_game->objects->warren,
        put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_WARREN].x
        + 1315, rpg->game->in_game->map->pos_map[MAP_WARREN].y + 3210));
        sfSprite_setTextureRect(rpg->game->in_game->objects->warren,
        rpg->game->in_game->objects->rect_warren);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->objects->warren, NULL);
    }
}