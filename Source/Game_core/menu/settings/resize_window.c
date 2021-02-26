/*
** EPITECH PROJECT, 2021
** resize the window by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** resize_window.c
*/

#include "../../../../include/defender.h"

float box_size_x(window_t *wnd, float x)
{
    sfVector2u wnd_size = sfRenderWindow_getSize(wnd->window);
    float adapt;

    adapt = (((float)x / 1920) * (float)wnd_size.x);
    return (adapt);
}

float box_size_y(window_t *wnd, float y)
{
    sfVector2u wnd_size = sfRenderWindow_getSize(wnd->window);
    float adapt;

    adapt = (((float)y / 1080) * (float)wnd_size.y);
    return (adapt);
}

void resize_wnd_med(window_t *wnd)
{
    sfVector2u resize = {1280, 720};
    sfVector2i wnd_pos = {350, 150};

    sfRenderWindow_setSize(wnd->window, resize);
    sfRenderWindow_setPosition(wnd->window, wnd_pos);
}

void resize_wnd_full(window_t *wnd)
{
    sfVector2u resize = {1920, 1080};
    sfVector2i wnd_pos = {0, 0};

    sfRenderWindow_setSize(wnd->window, resize);
    sfRenderWindow_setPosition(wnd->window, wnd_pos);
}
