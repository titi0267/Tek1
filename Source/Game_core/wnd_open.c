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
        choose_scene(core->menu, core->wnd);
        poll_event(core->wnd, core->menu);
        //my_printf("return : %i\n", core->menu->return_to_menu);
        //my_printf("setting : %i\n", core->menu->settings);
    }
    destroy_all(core);
}