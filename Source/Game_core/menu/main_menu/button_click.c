/*
** EPITECH PROJECT, 2021
** button click by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** button_click.c
*/

#include "../../../../include/defender.h"

void hover_play(button_t *button, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->play_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->play_spt).left) +
        box_size_x(wnd, sfSprite_getGlobalBounds(button->play_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->play_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->play_spt).top) +
        box_size_y(wnd, sfSprite_getGlobalBounds(button->play_spt).height))))
            sfRenderWindow_drawSprite(wnd->window,
                                    button->hover_play_spt, NULL);
        else
            sfRenderWindow_drawSprite(wnd->window, button->play_spt, NULL);
}
