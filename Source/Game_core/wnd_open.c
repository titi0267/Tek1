/*
** EPITECH PROJECT, 2021
** window open by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** window_open.c
*/

#include "../../include/defender.h"

void wnd_open(core_t *core)
{
    init(core);
    while (sfRenderWindow_isOpen(core->wnd->window)) {
        sfRenderWindow_drawSprite(core->wnd->window, core->wnd->sandwich1, NULL);
        sfRenderWindow_drawSprite(core->wnd->window, core->wnd->sandwich, NULL);
        poll_event(core->wnd);
        update_time(core->time);
        sfRenderWindow_display(core->wnd->window);
    }
    destroy1(core);
}