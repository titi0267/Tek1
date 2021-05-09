/*
** EPITECH PROJECT, 2021
** collisions
** File description:
** collisions.c
*/

#include "../../../include/func_name.h"

static int col_up(rpg_t *rpg, sfColor color, int pos_x, int pos_y)
{
    for (int z = pos_x; pos_x != (z - 50); pos_x--) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x
        + 4),
        (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real
        [rpg->game->in_game->map->status].y + 92);
        if (check_color(rpg, color) != 0)
            break;
    }
    return (check_color(rpg, color));
}

static int col_down(rpg_t *rpg, sfColor color, int pos_x, int pos_y)
{
    for (int z = pos_x; pos_x != (z - 50); pos_x--) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x
        + 4),
        (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real
        [rpg->game->in_game->map->status].y + 108);
        if (check_color(rpg, color) != 0)
            break;
    }
    return (check_color(rpg, color));
}

static int col_left(rpg_t *rpg, sfColor color, int pos_x, int pos_y)
{
    for (int z = pos_x; pos_x != z - 60; pos_x--) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x
        - 5), (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real
        [rpg->game->in_game->map->status].y + 95);
        if (check_color(rpg, color) != 0)
            break;
    }
    return (check_color(rpg, color));
}

static int col_right(rpg_t *rpg, sfColor color, int pos_x, int pos_y)
{
    for (int z = pos_x; pos_x != (z - 60); pos_x--) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x
        + 5),
        (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real
        [rpg->game->in_game->map->status].y + 95);
        if (check_color(rpg, color) != 0)
            break;
    }
    return (check_color(rpg, color));
}

int collision(rpg_t *rpg, int direction, int y)
{
    int pos_x = rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].x;
    int pos_y = rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y;
    sfColor color;

    if (direction == UP)
        return (col_up(rpg, color, pos_x, pos_y + y));
    if (direction == DOWN)
        return (col_down(rpg, color, pos_x, pos_y + y));
    if (direction == LEFT)
        return (col_left(rpg, color, pos_x - y, pos_y));
    if (direction == RIGHT)
        return (col_right(rpg, color, pos_x - y, pos_y));
    return (0);
}
