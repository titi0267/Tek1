/*
** EPITECH PROJECT, 2021
** resize the window by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** resize_window.c
*/

#include "../../../../include/defender.h"
#include <stdio.h>

float box_size(window_t *wnd)
{
    sfVector2u wnd_size = sfRenderWindow_getSize(wnd->window);
    float adapt;

    adapt = ((sfSprite_getGlobalBounds(wnd->sandwich1).left +
            sfSprite_getGlobalBounds(wnd->sandwich1).width) / 1920)
            * wnd_size.x;
    printf("pos= %f\n", ((sfSprite_getGlobalBounds(wnd->sandwich1).left +
            sfSprite_getGlobalBounds(wnd->sandwich1).width) / 1920));
    printf("wnd_sz = %i\n", wnd_size.x);
    return (adapt);
}

void resize_wnd(window_t *wnd)
{
    sfVector2u resize = {1280, 720};
    sfVector2i wnd_pos = {350, 150};

    printf("box= %2.f\n", box_size(wnd));
    sfRenderWindow_setSize(wnd->window, resize);
    sfRenderWindow_setPosition(wnd->window, wnd_pos);
    sfVector2f spt_pos = {box_size(wnd), 10};
    sfSprite_setPosition(wnd->sandwich1, spt_pos);
}
