/*
** EPITECH PROJECT, 2021
** background by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** background.c
*/

#include "../../../include/defender.h"

void mia(window_t *wnd)
{
    sfTexture *mia = sfTexture_createFromFile("Ressources/481_1000.jpg", NULL);
    wnd->sandwich = sfSprite_create();
    sfVector2f scale = {1.3f, 1.3f};

    sfSprite_setTexture(wnd->sandwich, mia, sfFalse);
    sfSprite_setScale(wnd->sandwich, scale);
}

void mia2(window_t *wnd)
{
    sfTexture *mia = sfTexture_createFromFile("Ressources/690_160.jpg", NULL);
    wnd->sandwich1 = sfSprite_create();
    sfVector2f scale = {1.3f, 1.3f};
    sfVector2f pos = {1080, 200};

    sfSprite_setTexture(wnd->sandwich1, mia, sfFalse);
    sfSprite_setPosition(wnd->sandwich1, pos);
    sfSprite_setScale(wnd->sandwich1, scale);
}