/*
** EPITECH PROJECT, 2021
** window open by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** window_open.c
*/

#include <stdio.h>
#include "../../include/defender.h"

void wnd_open(core_t *core)
{
    static int y = 0;
    init(core);
    while (sfRenderWindow_isOpen(core->wnd->window)) {
        y++;
        sfRenderWindow_display(core->wnd->window);
        if (core->menu->button->end_gm == TRUE &&
            core->menu->button->enable_click == FALSE)
            break;
        update_time(core);
        poll_event(core->wnd, core->menu);
        print_scene(core->menu, core->wnd, core->game, core);
        switch_bg(core->menu, core->game->pause);
    }
    destroy_all(core);
}