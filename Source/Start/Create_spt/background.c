/*
** EPITECH PROJECT, 2021
** background by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** background.c
*/

#include "../../../include/defender.h"

void backgd_menu(menu_t *menu)
{
    menu->bgd_tex = sfTexture_createFromFile("Ressources/MenuJeu-min.png",
                                            NULL);
    menu->bgd_spt = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(menu->bgd_spt, menu->bgd_tex, sfFalse);
    sfSprite_setScale(menu->bgd_spt, scale);
}

void mia2(window_t *wnd)
{
    sfTexture *mia = sfTexture_createFromFile("Ressources/690_160.jpg", NULL);
    wnd->sandwich1 = sfSprite_create();
    sfVector2f scale = {1.3f, 1.3f};
    wnd->pos.x = 1080;
    wnd->pos.y = 200;

    sfSprite_setTexture(wnd->sandwich1, mia, sfFalse);
    sfSprite_setPosition(wnd->sandwich1, wnd->pos);
    sfSprite_setScale(wnd->sandwich1, scale);
}