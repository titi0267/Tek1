/*
** EPITECH PROJECT, 2021
** events by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** events.c
*/

#include "../../include/defender.h"
#include <stdio.h>


void click_settings(menu_t *menu, sfEvent event, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd, sfSprite_getGlobalBounds(menu->button->setting_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd, sfSprite_getGlobalBounds(menu->button->setting_spt).left) +
            box_size_x(wnd, sfSprite_getGlobalBounds(menu->button->setting_spt).width))) &&
            (mouse_pos.y >= box_size_y(wnd, sfSprite_getGlobalBounds(menu->button->setting_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd, sfSprite_getGlobalBounds(menu->button->setting_spt).top) +
            box_size_y(wnd, sfSprite_getGlobalBounds(menu->button->setting_spt).height)))) {
            resize_wnd(wnd, menu);
        }
    }
}

void poll_event(window_t *wnd, menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wnd->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wnd->window);
        click_settings(menu, event, wnd);
    }
}