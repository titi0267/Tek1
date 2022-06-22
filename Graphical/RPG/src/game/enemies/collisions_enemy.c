/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** collisions_enemy
*/

#include "../../../include/func_name.h"

static int enemy_col_up(rpg_t *rpg, enemy_t *nmi_list, int pos_x, int pos_y)
{
    sfColor color;

    for (int z = pos_x; pos_x != (z - 55); pos_x--) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + nmi_list->nmi_pos.x
        + 4),
        (unsigned int)(pos_y * -1) + nmi_list->nmi_pos.y + 80);
        if (check_color(rpg, color) != 0)
            break;
    }
    return (check_color(rpg, color));

}

static int enemy_col_down(rpg_t *rpg, enemy_t *nmi_list, int pos_x, int pos_y)
{
    sfColor color;

    for (int z = pos_x; pos_x != (z - 55); pos_x--) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + nmi_list->nmi_pos.x
        + 4),
        (unsigned int)(pos_y * -1) + nmi_list->nmi_pos.y + 88);
        if (check_color(rpg, color) != 0)
            break;
    }
    return (check_color(rpg, color));
}

static int enemy_col_right(rpg_t *rpg, enemy_t *nmi_list, int pos_x, int pos_y)
{
    sfColor color;

    for (int z = pos_x; pos_x != (z - 40); pos_x--) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + nmi_list->nmi_pos.x
        + 5),
        (unsigned int)(pos_y * -1) + nmi_list->nmi_pos.y + 80);
        if (check_color(rpg, color) != 0)
            break;
    }
    return (check_color(rpg, color));
}

static int enemy_col_left(rpg_t *rpg, enemy_t *nmi_list, int pos_x, int pos_y)
{
    sfColor color;

    for (int z = pos_x; pos_x != z - 50; pos_x--) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)((pos_x * -1)
        + nmi_list->nmi_pos.x
        - 5), (unsigned int)(pos_y * -1) + nmi_list->nmi_pos.y + 80);
        if (check_color(rpg, color) != 0)
            break;
    }
    return (check_color(rpg, color));
}

int enemy_collision(rpg_t *rpg, int direction, enemy_t *nmi_list, int sub)
{
    int pos_x = rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].x;
    int pos_y = rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y;

    if (direction == UP)
        return (enemy_col_up(rpg, nmi_list, pos_x, pos_y + sub));
    if (direction == DOWN)
        return (enemy_col_down(rpg, nmi_list, pos_x, pos_y - sub));
    if (direction == RIGHT)
        return (enemy_col_right(rpg, nmi_list, pos_x - sub, pos_y));
    if (direction == LEFT)
        return (enemy_col_left(rpg, nmi_list, pos_x + sub, pos_y));
    return (0);
}