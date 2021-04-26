/*
** EPITECH PROJECT, 2021
** chose map
** File description:
** map_status.c
*/

#include "../../../include/func_name.h"

void print_map(rpg_t *rpg, int on_map)
{
    move_left_map(rpg, on_map);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->map->maps[on_map], NULL);
    print_player_move(rpg);
}

void chose_map(rpg_t *rpg)
{
    if (rpg->menu->status == ON_GAME) {
        rpg->game->in_game->map->status = MAP_INSIDE_POLICE;
        print_map(rpg, rpg->game->in_game->map->status);
    }
}

int collision(rpg_t *rpg, int on_map, int direction, int move)
{
    sfColor color;
    sfColor color2;
    move++;

    if (direction == UP) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions[on_map],
        (unsigned int)((rpg->game->in_game->map->pos_map[on_map].x * -1) + 930),
        (unsigned int)(rpg->game->in_game->map->pos_map[on_map].y * -1) + 580);
        color2 = sfImage_getPixel(rpg->game->in_game->map->collisions[on_map],
        (unsigned int)((rpg->game->in_game->map->pos_map[on_map].x * -1) + 990),
        (unsigned int)(rpg->game->in_game->map->pos_map[on_map].y * -1) + 580);
    }
    if (direction == DOWN) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions[on_map],
        (unsigned int)((rpg->game->in_game->map->pos_map[on_map].x * -1) + 930),
        (unsigned int)(rpg->game->in_game->map->pos_map[on_map].y * -1) + 593);
        color2 = sfImage_getPixel(rpg->game->in_game->map->collisions[on_map],
        (unsigned int)((rpg->game->in_game->map->pos_map[on_map].x * -1) + 990),
        (unsigned int)(rpg->game->in_game->map->pos_map[on_map].y * -1) + 593);
    }
    if (direction == LEFT) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions[on_map],
        (unsigned int)((rpg->game->in_game->map->pos_map[on_map].x * -1) + 930),
        (unsigned int)(rpg->game->in_game->map->pos_map[on_map].y * -1) + 580);
        color2 = sfImage_getPixel(rpg->game->in_game->map->collisions[on_map],
        (unsigned int)((rpg->game->in_game->map->pos_map[on_map].x * -1) + 930),
        (unsigned int)(rpg->game->in_game->map->pos_map[on_map].y * -1) + 580);
    }
    if (direction == RIGHT) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions[on_map],
        (unsigned int)((rpg->game->in_game->map->pos_map[on_map].x * -1) + 990),
        (unsigned int)(rpg->game->in_game->map->pos_map[on_map].y * -1) + 580);
        color2 = sfImage_getPixel(rpg->game->in_game->map->collisions[on_map],
        (unsigned int)((rpg->game->in_game->map->pos_map[on_map].x * -1) + 990),
        (unsigned int)(rpg->game->in_game->map->pos_map[on_map].y * -1) + 580);
    }
    if (compare_equal_colors(rpg->game->in_game->map->color, color) == 1 ||
        compare_equal_colors(rpg->game->in_game->map->color, color2) == 1)
        return (COLLISION);
    return (0);
}