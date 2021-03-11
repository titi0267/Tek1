/*
** EPITECH PROJECT, 2021
** window open by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** window_open.c
*/

#include "../../include/defender.h"
#include <stdio.h>

void wnd_open(core_t *core)
{
    init(core);
    while (sfRenderWindow_isOpen(core->wnd->window)) {
        sfRenderWindow_display(core->wnd->window);
        if (core->menu->button->end_gm == TRUE &&
            core->menu->button->enable_click == FALSE)
            break;
        update_time(core->time);
        switch_bg(core->menu);
        print_scene(core->menu, core->wnd, core->game);
        poll_event(core->wnd, core->menu);
    }
    destroy_all(core);
}