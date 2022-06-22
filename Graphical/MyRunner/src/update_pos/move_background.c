/*
** EPITECH PROJECT, 2021
** move background by Timothy CONIEL
** File description:
** move_background.c
*/

#include "../../include/my.h"

void background_update(sfRenderWindow *window, background_t *back)
{
    back->position_back.x -= 0.5f;
    back->pos_back.x -= 0.5f;
    sfSprite_setPosition(back->my_background, back->position_back);
    sfRenderWindow_drawSprite(window, back->my_background, NULL);
    sfSprite_setPosition(back->my_background1, back->pos_back);
    sfRenderWindow_drawSprite(window, back->my_background1, NULL);
    if (back->position_back.x <= -1350 || back->pos_back.x <= 0)
        init_background(back);
}

void bottom_update(sfRenderWindow *window, background_t *back)
{
    back->position_bott.x -= 4;
    back->pos_bottom.x -= 4;
    sfSprite_setPosition(back->my_bottom1, back->pos_bottom);
    sfRenderWindow_drawSprite(window, back->my_bottom1, NULL);
    sfSprite_setPosition(back->my_bottom, back->position_bott);
    sfRenderWindow_drawSprite(window, back->my_bottom, NULL);
    if (back->position_bott.x <= -1350 || back->pos_bottom.x <= 0)
        init_bottom(back);
}
