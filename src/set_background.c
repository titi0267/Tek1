/*
** EPITECH PROJECT, 2020
** Set Background by Timmothy CONIEL
** File description:
** set_background.c
*/
#include "../include/my.h"

void background(sfRenderWindow *window, background_t *back)
{
    sfTexture *background = sfTexture_createFromFile("png/building.png", NULL);
    sfSprite *my_background = sfSprite_create();
    sfVector2f scale = {1.5f, 1.5f};

    sfSprite_setPosition(my_background, back->position_back);
    sfSprite_setTexture(my_background, background, sfFalse);
    sfSprite_setScale(my_background, scale);
    sfRenderWindow_drawSprite(window, my_background, NULL);
    sfSprite_destroy(my_background);
    sfTexture_destroy(background);
}

void next_background(sfRenderWindow *window, background_t *back)
{
    sfTexture *background = sfTexture_createFromFile("png/building.png", NULL);
    sfSprite *my_background = sfSprite_create();
    sfVector2f scale = {1.5f, 1.5f};

    sfSprite_setPosition(my_background, back->pos_back);
    sfSprite_setTexture(my_background, background, sfFalse);
    sfSprite_setScale(my_background, scale);
    sfRenderWindow_drawSprite(window, my_background, NULL);
    sfSprite_destroy(my_background);
    sfTexture_destroy(background);
}

void bottom(sfRenderWindow *window, background_t *back)
{
    sfTexture *bottom = sfTexture_createFromFile("png/bottom.png", NULL);
    sfSprite *my_bottom = sfSprite_create();
    sfVector2f scale = {1.6959f, 1};

    sfSprite_setPosition(my_bottom, back->position_bott);
    sfSprite_setTexture(my_bottom, bottom, sfFalse);
    sfSprite_setScale(my_bottom, scale);
    sfRenderWindow_drawSprite(window, my_bottom, NULL);
    sfSprite_destroy(my_bottom);
    sfTexture_destroy(bottom);
}

void next_bottom(sfRenderWindow *window, background_t *back)
{
    sfTexture *bottom = sfTexture_createFromFile("png/bottom.png", NULL);
    sfSprite *my_bottom = sfSprite_create();
    sfVector2f scale = {1.6959f, 1};

    sfSprite_setPosition(my_bottom, back->pos_bottom);
    sfSprite_setTexture(my_bottom, bottom, sfFalse);
    sfSprite_setScale(my_bottom, scale);
    sfRenderWindow_drawSprite(window, my_bottom, NULL);
    sfSprite_destroy(my_bottom);
    sfTexture_destroy(bottom);
}

void set_background(sfRenderWindow *window, background_t *back)
{
    background(window, back);
    next_background(window, back);
    bottom(window, back);
    next_bottom(window, back);
}