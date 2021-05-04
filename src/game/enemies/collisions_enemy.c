/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** collisions_enemy
*/

#include "../../../include/func_name.h"
/*
int enemy_col_up(rpg_t *rpg, sfColor color, int pos_x, int pos_y)
{
    return (0);
}

int enemy_col_down(rpg_t *rpg, sfColor color, int pos_x, int pos_y)
{
    return (0);
}

int enemy_col_right(rpg_t *rpg, sfColor color, int pos_x, int pos_y)
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
    return (0);
}*/

/*int enemy_col_left(rpg_t *rpg, sfColor color, int pos_x, int pos_y)
{
    return (0);
}*/

int enemy_collision(rpg_t *rpg, int direction, enemy_t *nmi_list)
{
    //sfColor color;
    int pos_x = nmi_list->nmi_pos.x;
    int pos_y = rpg->game->in_game->nmi_list->nmi_pos.y;

    if (direction == 10)
        return (1);
    pos_y++;
    pos_x++;
    return (0);
    /*if (direction == UP)
        enemy_col_up(rpg, color, pos_x, pos_y);
    if (direction == DOWN)
        enemy_col_down(rpg, color, pos_x, pos_y);
    if (direction == RIGHT)
        enemy_col_right(rpg, color, pos_x, pos_y);
    if (direction == LEFT)
        enemy_col_left(rpg, color, pos_x, pos_y);*/
}