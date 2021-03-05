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
        if (event.type == sfEvtMouseButtonPressed)
            menu->button->enable_click = TRUE;
        if (event.type == sfEvtMouseButtonReleased)
            menu->button->enable_click = FALSE;
        leave_gm(menu, menu->button, event, wnd);
        click_resize_full(menu->stg, wnd, event);
        return_to_menu(menu, menu->stg, event, wnd);
        if (menu->button->enable_click == TRUE) {
            click_up_vol(menu->stg->vol, wnd);
            click_down_vol(menu->stg->vol, wnd);
        }
        click_settings(menu, event, wnd);
    }
}
