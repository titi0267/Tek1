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
    menu->pos_black.x = 500;
    menu->pos_black.y = 400;
    sfSprite_setPosition(menu->button, menu->position);
    menu->scale.x = 5;
    menu->scale.y = 5;
    menu->black_scale.x = 4;
    menu->black_scale.y = 4;
}

void create_button(menu_t *menu)
{
    menu->button = sfSprite_create();
    menu->button_tex = sfTexture_createFromFile("png/off_button.png", NULL);
    init_button(menu);
    sfSprite_setTexture(menu->button, menu->button_tex, sfFalse);
    sfSprite_setScale(menu->button, menu->scale);
}

void create_load(menu_t *menu)
{
    menu->load = sfSprite_create();
    menu->loading = sfTexture_createFromFile("png/loading.png", NULL);
    sfVector2f scale = {1, 1};
    sfVector2f position = {200, 100};

    sfSprite_setTexture(menu->load, menu->loading, sfFalse);
    sfSprite_setScale(menu->load, scale);
    sfSprite_setPosition(menu->load, position);
}

void create_button_black(menu_t *menu)
{
    menu->black_but = sfSprite_create();
    menu->black_tex = sfTexture_createFromFile("png/on_button.png", NULL);
    init_button(menu);
    sfSprite_setTexture(menu->black_but, menu->black_tex, sfFalse);
    sfSprite_setScale(menu->black_but, menu->scale);
    sfSprite_setPosition(menu->black_but, menu->pos_black);
}
