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
        /*if (compare_equal_colors(rpg->game->in_game->map->color
        [PASS], color) == 1)
            return (BTW_MAP);*/
        return (0);
    }
    return (0);
}

int check_collision(rpg_t *rpg, int direction)
{
    int d = collision(rpg, direction);
    sfColor color;
    /*sfColor color = sfSprite_getColor(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen]);
    printf("color = r %i g %i b %i\n", color.r, color.g, color.b);
    if (color.r == 0 && color.g == 0 && color.b == 0 && d != BEHIND)
        sfSprite_setTexture(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], rpg->game->in_game->objects->player_tex
        [rpg->menu->main_menu->new_game->character_chosen], sfTrue);
*/
    if (d != BEHIND)
        sfSprite_setColor(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], sfWhite);
    if (d == COLLISION) {
        return (COLLISION);
    }
    if (d == BEHIND) {
        /*printf("mask : r = %i & g = %i & b = %i\n color : r = %i & g = %i & b = %i\n", rpg->game->in_game->map->color
        [MASK].r, rpg->game->in_game->map->color
        [MASK].b, rpg->game->in_game->map->color
        [MASK].b, color.r, color.g, color.b);*/
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = 128;
        sfSprite_setColor(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], color);
    }
    if (d == BTW_MAP) {
        //change map;
        return (0);
    }
    return (0);
}
