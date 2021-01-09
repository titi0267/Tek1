/*
** EPITECH PROJECT, 2020
** Set Background by Timothy CONIEL
** File description:
** set_background.c
*/
#include "../include/my.h"

void background(background_t *back)
{
    back->background = sfTexture_createFromFile("png/building.png", NULL);
    back->my_background = sfSprite_create();
    back->background1 = sfTexture_createFromFile("png/building.png", NULL);
    back->my_background1 = sfSprite_create();
    sfVector2f scale = {1.5f, 1.5f};

    sfSprite_setTexture(back->my_background, back->background, sfFalse);
    sfSprite_setScale(back->my_background, scale);
    sfSprite_setTexture(back->my_background1, back->background1, sfFalse);
    sfSprite_setScale(back->my_background1, scale);
    init_background(back);
}

void bottom(background_t *back)
{
    back->bottom = sfTexture_createFromFile("png/bottom.png", NULL);
    back->bottom1 = sfTexture_createFromFile("png/bottom.png", NULL);
    back->my_bottom = sfSprite_create();
    back->my_bottom1 = sfSprite_create();
    sfVector2f scale = {1.6959f, 1};

    sfSprite_setTexture(back->my_bottom, back->bottom, sfFalse);
    sfSprite_setTexture(back->my_bottom1, back->bottom1, sfFalse);
    sfSprite_setScale(back->my_bottom, scale);
    sfSprite_setScale(back->my_bottom1, scale);
    init_bottom(back);
}

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
