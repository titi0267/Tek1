/*
** EPITECH PROJECT, 2021
** end button by Timothy CONIEL
** File description:
** end_button.c
*/
#include "../include/my.h"

void init_button(menu_t *menu)
{
    menu->position.x = 500;
    menu->position.y = 400;
    sfSprite_setPosition(menu->button, menu->position);
}

void create_button(menu_t *menu)
{
    menu->button_tex = sfTexture_createFromFile("png/off_button.png", NULL);
    menu->button = sfSprite_create();
    menu->scale.x = 5;
    menu->scale.y = 5;

    sfSprite_setTexture(menu->button, menu->button_tex, sfFalse);
    sfSprite_setScale(menu->button, menu->scale);
    init_button(menu);
}

void update_button(gather_t *gather)
{
    sfRenderWindow_drawSprite(gather->windo.window, gather->menu.button, NULL);
}
