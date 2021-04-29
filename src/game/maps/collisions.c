/*
** EPITECH PROJECT, 2021
** collisions
** File description:
** collisions.c
*/

#include "../../../include/func_name.h"

int col_up(rpg_t *rpg, sfColor *color, int pos_x, int pos_y)
{
    for (int z = pos_x; pos_x != (z - 60); pos_x--) {
        color[0] = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x),
        (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real
        [rpg->game->in_game->map->status].y + 95);
        if (compare_equal_colors(rpg->game->in_game->map->color, color[0]) == 1) {
            free(color);
            return (COLLISION);
        }
    }
    free(color);
    return (0);
}

int col_down(rpg_t *rpg, sfColor *color, int pos_x, int pos_y)
{
    for (int z = pos_x; pos_x != (z - 60); pos_x--) {
        color[0] = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x),
        (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real
        [rpg->game->in_game->map->status].y + 108);
        if (compare_equal_colors(rpg->game->in_game->map->color, color[0]) == 1) {
            free(color);
            return (COLLISION);
        }
    }
    free(color);
    return (0);
}

int col_left(rpg_t *rpg, sfColor *color, int pos_x, int pos_y)
{
    color[0] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
    + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real
    [rpg->game->in_game->map->status].y + 95);
    if (compare_equal_colors(rpg->game->in_game->map->color, color[0]) == 1) {
        free(color);
        return (COLLISION);
    }
    free(color);
    return (0);
}

int col_right(rpg_t *rpg, sfColor *color, int pos_x, int pos_y)
{
    color[0] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
    + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x + 60),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real
    [rpg->game->in_game->map->status].y + 95);
    if (compare_equal_colors(rpg->game->in_game->map->color, color[0]) == 1) {
        free(color);
        return (COLLISION);
    }
    free(color);
    return (0);
}

int collision(rpg_t *rpg, int direction)
{
    int pos_x = rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].x;
    int pos_y = rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y;
    sfColor *color;

    color = malloc(sizeof(sfColor) * 3);
    if (direction == UP)
        return (col_up(rpg, color, pos_x, pos_y));
    if (direction == DOWN)
        return (col_down(rpg, color, pos_x, pos_y));
    if (direction == LEFT)
        return (col_left(rpg, color, pos_x, pos_y));
    if (direction == RIGHT)
        return (col_right(rpg, color, pos_x, pos_y));
    return (0);
}
