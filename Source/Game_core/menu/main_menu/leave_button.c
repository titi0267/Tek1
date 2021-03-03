/*
** EPITECH PROJECT, 2021
** leave button by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** leave_button.c
*/

#include "../../../../include/defender.h"

void hover_leave_but(button_t *button)
{
    button->hover_leave_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/leav_on.png",
                        NULL);
    button->hover_leave_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1600, 50};

    sfSprite_setTexture(button->hover_leave_spt,
                        button->hover_leave_tex, sfFalse);
    sfSprite_setPosition(button->hover_leave_spt, setting_pos);
    sfSprite_setScale(button->hover_leave_spt, scale);
}

void click_leave_but(button_t *button)
{
    button->hover_leave_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/leav_on.png",
                        NULL);
    button->hover_leave_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1600, 50};

    sfSprite_setTexture(button->hover_leave_spt,
                        button->hover_leave_tex, sfFalse);
    sfSprite_setPosition(button->hover_leave_spt, setting_pos);
    sfSprite_setScale(button->hover_leave_spt, scale);
}

void button_leave(menu_t *menu, button_t *button)
{
    button->leave_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/leave.png",
                        NULL);
    button->leave_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f leave_pos = {1600, 50};

    sfSprite_setTexture(button->leave_spt, button->leave_tex, sfFalse);
    sfSprite_setPosition(button->leave_spt, leave_pos);
    sfSprite_setScale(button->leave_spt, scale);
    menu->end_gm = FALSE;
}

void hover_leave(button_t *button, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->leave_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->leave_spt).left) +
        box_size_x(wnd, sfSprite_getGlobalBounds(button->leave_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->leave_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->leave_spt).top) +
        box_size_y(wnd, sfSprite_getGlobalBounds(button->leave_spt).height))))
            sfRenderWindow_drawSprite(wnd->window,
                                    button->hover_leave_spt, NULL);
        else
            sfRenderWindow_drawSprite(wnd->window, button->leave_spt, NULL);
}

void leave_gm(menu_t *menu, button_t *button, sfEvent event, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->leave_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                            sfSprite_getGlobalBounds(button->leave_spt).left) +
            box_size_x(wnd, sfSprite_getGlobalBounds(button->leave_spt).width)))
            && (mouse_pos.y >= box_size_y(wnd,
                            sfSprite_getGlobalBounds(button->leave_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                            sfSprite_getGlobalBounds(button->leave_spt).top) +
            box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->leave_spt).height))))
                menu->end_gm = TRUE;
    }
}
