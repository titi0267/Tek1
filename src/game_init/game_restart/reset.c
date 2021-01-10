/*
** EPITECH PROJECT, 2021
** reset by Timothy CONIEL
** File description:
** reset.c
*/
#include "../../../include/my.h"

void init_button(menu_t *menu)
{
    menu->position.x = 500;
    menu->position.y = 400;
    menu->pos_black.x = 500;
    menu->pos_black.y = 400;
    sfSprite_setPosition(menu->button, menu->position);
    menu->scale.x = 5;
    menu->scale.y = 5;
    menu->black_scale.x = 4;
    menu->black_scale.y = 4;
}

void restart(gather_t *gather, map_t *buff)
{
    if (gather->menu.black_scale.x >= 5 || gather->menu.black_scale.y >= 5)
        gather->menu.restart = 1;
    if (gather->menu.restart == 1)
        re_init(gather, buff);
}
