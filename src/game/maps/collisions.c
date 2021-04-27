/*
** EPITECH PROJECT, 2021
** collisions
** File description:
** collisions.c
*/

#include "../../../include/func_name.h"

sfColor *col_up(rpg_t *rpg, sfColor *color, int pos_x, int pos_y)
{
    color[0] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].y + 95);
    color[1] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x + 60),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].y + 95);
    return (color);
}

sfColor *col_down(rpg_t *rpg, sfColor *color, int pos_x, int pos_y)
{
    color[0] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].y + 108);
    color[1] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x + 60),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].y + 108);
    return (color);
}

sfColor *col_left(rpg_t *rpg, sfColor *color, int pos_x, int pos_y)
{
    color[0] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].y + 95);
    color[1] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].y + 95);
    return (color);
}

sfColor *col_right(rpg_t *rpg, sfColor *color, int pos_x, int pos_y)
{
    color[0] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x + 60),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].y + 95);
    color[1] = sfImage_getPixel(rpg->game->in_game->map->collisions
    [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x + 60),
    (unsigned int)(pos_y * -1) + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].y + 95);
    return (color);
}

sfColor *assemble_col(rpg_t *rpg, int direction, sfColor *color)
{
    int pos_x = rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].x;
    int pos_y = rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y;

    if (direction == UP)
        color = col_up(rpg, color, pos_x, pos_y);
    if (direction == DOWN)
        color = col_down(rpg, color, pos_x, pos_y);
    if (direction == LEFT)
        color = col_left(rpg, color, pos_x, pos_y);
    if (direction == RIGHT)
        color = col_right(rpg, color, pos_x, pos_y);
    return (color);
}

int collision(rpg_t *rpg, int direction)
{
    sfColor *color;

    color = malloc(sizeof(sfColor) * 3);
    color = assemble_col(rpg, direction, color);
    if (compare_equal_colors(rpg->game->in_game->map->color, color[0]) == 1 ||
        compare_equal_colors(rpg->game->in_game->map->color, color[1]) == 1) {
        free(color);
        return (COLLISION);
    }
    free(color);
    return (0);
}