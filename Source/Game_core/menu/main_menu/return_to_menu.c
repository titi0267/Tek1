/*
** EPITECH PROJECT, 2021
** return to main menu by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** return_to_menu.c
*/

#include "../../../../include/defender.h"

void back_to_menu_spt(button_t *button, menu_t *menu)
{
    button->return_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/undo.png",
                        NULL);
    button->return_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f return_pos = {2020, 50};

    sfSprite_setTexture(button->return_spt, button->return_tex, sfFalse);
    sfSprite_setPosition(button->return_spt, return_pos);
    sfSprite_setScale(button->return_spt, scale);
    menu->return_to_menu = FALSE;
}

void hover_back_to_menu_spt(button_t *button)
{
    button->hover_return_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/undo_on.png",
                        NULL);
    button->hover_return_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f hover_return_pos = {2020, 50};

    sfSprite_setTexture(button->hover_return_spt, button->hover_return_tex, sfFalse);
    sfSprite_setPosition(button->hover_return_spt, hover_return_pos);
    sfSprite_setScale(button->hover_return_spt, scale);
}

void hover_return(button_t *button, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->return_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->return_spt).left) +
        box_size_x(wnd, sfSprite_getGlobalBounds(button->return_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->return_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->return_spt).top) +
        box_size_y(wnd, sfSprite_getGlobalBounds(button->return_spt).height))))
            sfRenderWindow_drawSprite(wnd->window,
                                    button->hover_return_spt, NULL);
        else
            sfRenderWindow_drawSprite(wnd->window, button->return_spt, NULL);
}

void return_to_menu(menu_t *menu, button_t *button, sfEvent event, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->return_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                            sfSprite_getGlobalBounds(button->return_spt).left) +
            box_size_x(wnd, sfSprite_getGlobalBounds(button->return_spt).width)))
            && (mouse_pos.y >= box_size_y(wnd,
                            sfSprite_getGlobalBounds(button->return_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                            sfSprite_getGlobalBounds(button->return_spt).top) +
            box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->return_spt).height))))
                menu->return_to_menu = TRUE;
    }
}