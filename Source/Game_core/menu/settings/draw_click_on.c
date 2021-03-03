/*
** EPITECH PROJECT, 2021
** draw button clicked by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** draw_click_on.c
*/

#include "../../../../include/defender.h"

void draw_spt_click(menu_t *menu, sfEvent event, window_t *wnd)
{
    if (event.type == sfEvtMouseButtonPressed) {
        click_on_play(menu, wnd);
    }
}

void click_on_play(button_t *button, window_t *wnd)
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
                                    button->click_play_spt, NULL);
}

void click_on_play(button_t *button, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->setting_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->setting_spt).left) +
        box_size_x(wnd, sfSprite_getGlobalBounds(button->setting_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->setting_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->play_spt).top) +
        box_size_y(wnd, sfSprite_getGlobalBounds(button->play_spt).height))))
            sfRenderWindow_drawSprite(wnd->window,
                                    button->click_play_spt, NULL);
}