/*
** EPITECH PROJECT, 2021
** resize window buttons by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** resize_button.c
*/

#include "../../../../include/defender.h"

void fullscr_button(button_t *button, menu_t *menu)
{
    button->fullscr_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/button/1920-1080.png",
                            NULL);
    button->fullscr_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f fullscr_pos = {3320, 400};

    sfSprite_setTexture(button->fullscr_spt, button->fullscr_tex, sfFalse);
    sfSprite_setPosition(button->fullscr_spt, fullscr_pos);
    sfSprite_setScale(button->fullscr_spt, scale);
}

void medscr_button(button_t *button, menu_t *menu)
{
    button->medscr_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/button/1280-720.png",
                            NULL);
    button->medscr_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f medscr_pos = {3320, 600};

    sfSprite_setTexture(button->medscr_spt, button->medscr_tex, sfFalse);
    sfSprite_setPosition(button->medscr_spt, medscr_pos);
    sfSprite_setScale(button->medscr_spt, scale);
}

void click_resize_med(menu_t *menu, window_t *wnd, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->button->medscr_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->button->medscr_spt).left) +
            box_size_x(wnd,
                sfSprite_getGlobalBounds(menu->button->medscr_spt).width))) &&
            (mouse_pos.y >= box_size_y(wnd,
                    sfSprite_getGlobalBounds(menu->button->medscr_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                    sfSprite_getGlobalBounds(menu->button->medscr_spt).top) +
            box_size_y(wnd,
                sfSprite_getGlobalBounds(menu->button->medscr_spt).height))))
                resize_wnd_med(wnd);
    }
}

void click_resize_full(menu_t *menu, window_t *wnd, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->button->fullscr_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->button->fullscr_spt).left) +
            box_size_x(wnd,
                sfSprite_getGlobalBounds(menu->button->fullscr_spt).width))) &&
            (mouse_pos.y >= box_size_y(wnd,
                    sfSprite_getGlobalBounds(menu->button->fullscr_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                    sfSprite_getGlobalBounds(menu->button->fullscr_spt).top) +
            box_size_y(wnd,
                sfSprite_getGlobalBounds(menu->button->fullscr_spt).height))))
                resize_wnd_full(wnd);
    }
}
