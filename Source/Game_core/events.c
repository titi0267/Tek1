/*
** EPITECH PROJECT, 2021
** events by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** events.c
*/

#include "../../include/defender.h"

void poll_event(window_t *wnd, menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wnd->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wnd->window);
        click_settings(menu, event, wnd);
        leave_gm(menu, menu->button, event, wnd);
        click_resize_full(menu, wnd, event);
        click_resize_med(menu, wnd, event);
        return_to_menu(menu, menu->button, event, wnd);
    }
}