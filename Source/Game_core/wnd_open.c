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
        poll_event(core->wnd, core->menu);
        update_time(core->time);
        main_menu_draw(core->menu, core->wnd);
        sfRenderWindow_display(core->wnd->window);
    }
    destroy1(core);
}