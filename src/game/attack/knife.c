/*
** EPITECH PROJECT, 2021
** knife
** File description:
** knife
*/

#include "../../../include/func_name.h"

void draw_knife(rpg_t *rpg)
{
    if (rpg->game->in_game->map->last_pos == RIGHT)
        sfSprite_setPosition(rpg->game->in_game->objects->knife,
        put_in_vector2f(980, 502));
    if (rpg->game->in_game->map->last_pos == LEFT) {
        sfSprite_setRotation(rpg->game->in_game->objects->knife, 180);
        sfSprite_setPosition(rpg->game->in_game->objects->knife,
        put_in_vector2f(940, 582));
    }
    if (rpg->game->in_game->map->last_pos == UP) {
        sfSprite_setRotation(rpg->game->in_game->objects->knife, 270);
        sfSprite_setPosition(rpg->game->in_game->objects->knife,
        put_in_vector2f(920, 492));
    }
    if (rpg->game->in_game->map->last_pos == DOWN) {
        sfSprite_setRotation(rpg->game->in_game->objects->knife, 90);
        sfSprite_setPosition(rpg->game->in_game->objects->knife,
        put_in_vector2f(1000, 572));
    }
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->objects->knife, NULL);
    sfSprite_setRotation(rpg->game->in_game->objects->knife, 0);
}