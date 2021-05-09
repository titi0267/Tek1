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

int check_collision_again(rpg_t *rpg, int direction)
{
    int d = 0;
    sfColor color;

    d = collision(rpg, direction, 4);
    if (d == COLLISION) {
    sfSprite_setColor(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen], sfWhite);
    sfSprite_setColor(rpg->game->in_game->objects->player_vest
    [rpg->menu->main_menu->new_game->character_chosen], sfWhite);
        return (COLLISION);
    }
    else if (d == BEHIND) {
        color.r = 128;
        color.g = 128;
        color.b = 128;
        color.a = 80;
        sfSprite_setColor(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], color);
        sfSprite_setColor(rpg->game->in_game->objects->player_vest
        [rpg->menu->main_menu->new_game->character_chosen], color);
        if (rpg->game->in_game->objects->speed_status == CAR_SPEED)
            sfSprite_setColor(rpg->game->in_game->objects->car->car, color);
        return (COLLISION);
    }
    return (-1);
}

int check_collision(rpg_t *rpg, int direction)
{
    int d = collision(rpg, direction, 0);
    int f = 0;
    sfColor color;

    if (d != BEHIND && d != COLLISION) {
        sfSprite_setColor(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], sfWhite);
        sfSprite_setColor(rpg->game->in_game->objects->player_vest
        [rpg->menu->main_menu->new_game->character_chosen], sfWhite);
        if (rpg->game->in_game->objects->speed_status == CAR_SPEED)
            sfSprite_setColor(rpg->game->in_game->objects->car->car, sfWhite);
    }
    if (d == COLLISION)
        if ((f = check_collision_again(rpg, direction)) != -1)
            return (d);
    if (d == BEHIND) {
        color.r = 128;
        color.g = 128;
        color.b = 128;
        color.a = 80;
        sfSprite_setColor(rpg->game->in_game->objects->players
        [rpg->menu->main_menu->new_game->character_chosen], color);
        sfSprite_setColor(rpg->game->in_game->objects->player_vest
        [rpg->menu->main_menu->new_game->character_chosen], color);
        if (rpg->game->in_game->objects->speed_status == CAR_SPEED)
            sfSprite_setColor(rpg->game->in_game->objects->car->car, color);
    }
    if (d == BTW_MAP)
        change_map(rpg);
    return (0);
}