/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tools
*/

#include "../include/func_name.h"

float adapt_x(rpg_t *rpg, int hitbox_x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->basic->wnd->my_wnd);
    float result = 0;

    result = (((float)hitbox_x / 1920) * (float)window_size.x);
    return (result);
}

float adapt_y(rpg_t *rpg, int hitbox_y)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->basic->wnd->my_wnd);
    float result = 0;

    result = (((float)hitbox_y / 1080) * (float)window_size.y);
    return (result);
}