/*
** EPITECH PROJECT, 2021
** click on resize by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** click_on_resize.c
*/

#include "../../../../include/defender.h"

void click_resize_med(settings_t *stg, window_t *wnd, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                    sfSprite_getGlobalBounds(stg->medscr_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                    sfSprite_getGlobalBounds(stg->medscr_spt).left) +
            box_size_x(wnd,
                sfSprite_getGlobalBounds(stg->medscr_spt).width))) &&
            (mouse_pos.y >= box_size_y(wnd,
                    sfSprite_getGlobalBounds(stg->medscr_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                    sfSprite_getGlobalBounds(stg->medscr_spt).top) +
            box_size_y(wnd,
                sfSprite_getGlobalBounds(stg->medscr_spt).height))))
                resize_wnd_med(wnd);
    }
}

void click_resize_full(settings_t *stg, window_t *wnd, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                    sfSprite_getGlobalBounds(stg->fullscr_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                    sfSprite_getGlobalBounds(stg->fullscr_spt).left) +
            box_size_x(wnd,
                sfSprite_getGlobalBounds(stg->fullscr_spt).width))) &&
            (mouse_pos.y >= box_size_y(wnd,
                    sfSprite_getGlobalBounds(stg->fullscr_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                    sfSprite_getGlobalBounds(stg->fullscr_spt).top) +
            box_size_y(wnd,
                sfSprite_getGlobalBounds(stg->fullscr_spt).height))))
                resize_wnd_full(wnd);
    }
}
