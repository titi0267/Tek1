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
    printf("left = %2.f & width = %2.f\n", sfSprite_getGlobalBounds(wnd->sandwich1).left, sfSprite_getGlobalBounds(wnd->sandwich1).width);
    if (event.type == sfEvtMouseButtonPressed) {
        if (mouse_pos.x >= sfSprite_getGlobalBounds(wnd->sandwich1).left &&
            mouse_pos.x <= (sfSprite_getGlobalBounds(wnd->sandwich1).left +
            sfSprite_getGlobalBounds(wnd->sandwich1).width)) {
            my_printf("mouse_pos = %i\n", mouse_pos.x);
            resize_wnd(wnd);
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