/*
** EPITECH PROJECT, 2021
** collisions
** File description:
** collisions.c
*/

#include "../../../include/func_name.h"

int check_color(rpg_t *rpg, sfColor color)
{
    if (compare_equal_colors(rpg->game->in_game->map->color
        [COL], color) == 1)
        return (COLLISION);
    else if (compare_equal_colors(rpg->game->in_game->map->color
        [MASK], color) == 1) {
        return (BEHIND);
    } else {
        if (compare_equal_colors(rpg->game->in_game->map->color
        [PASS], color) == 1)
            return (BTW_MAP);
    }
    return (0);
}

int check_collision(rpg_t *rpg, int direction)
{
    int d = collision(rpg, direction, 0);
    sfColor color;

    if (d != BEHIND && d != COLLISION) {
        sfSprite_setColor(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], sfWhite);
    }
    if (d == COLLISION) {
        d = collision(rpg, direction, 4);
        if (d == COLLISION) {
        sfSprite_setColor(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], sfWhite);
            return (COLLISION);
        }
        else if (d == BEHIND) {
            color.r = 0;
            color.g = 0;
            color.b = 0;
            color.a = 128;
            sfSprite_setColor(rpg->game->in_game->objects->players
            [rpg->menu->main_menu->new_game->character_chosen], color);
            return (COLLISION);
        }
    }
    if (d == BEHIND) {
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = 128;
        sfSprite_setColor(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], color);
    }
    if (d == BTW_MAP) {
        change_map(rpg);
    }
    return (0);
}
