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
        if (core->menu->end_gm == TRUE)
            break;
        update_time(core->time);
        if (core->menu->settings == FALSE)
            main_menu_draw(core->menu, core->wnd);
        else
            draw_spt_setting(core->menu, core->wnd);
        poll_event(core->wnd, core->menu);
        sfRenderWindow_display(core->wnd->window);
    }
    destroy1(core);
}