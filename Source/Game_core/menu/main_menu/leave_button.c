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
                        "Ressources/button/menu/leave/hover_leave.png",
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
    button->click_leave_tex = sfTexture_createFromFile(
                        "Ressources/button/menu/leave/click_leave.png",
                        NULL);
    button->click_leave_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1600, 50};

    sfSprite_setTexture(button->click_leave_spt,
                        button->click_leave_tex, sfFalse);
    sfSprite_setPosition(button->click_leave_spt, setting_pos);
    sfSprite_setScale(button->click_leave_spt, scale);
}

void button_leave(menu_t *menu, button_t *button)
{
    button->leave_tex = sfTexture_createFromFile(
                        "Ressources/button/menu/leave/leave.png",
                        NULL);
    button->leave_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f leave_pos = {1600, 50};

    sfSprite_setTexture(button->leave_spt, button->leave_tex, sfFalse);
    sfSprite_setPosition(button->leave_spt, leave_pos);
    sfSprite_setScale(button->leave_spt, scale);
    menu->button->end_gm = FALSE;
}

void draw_leave(button_t *button, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect leave_spt = sfSprite_getGlobalBounds(button->leave_spt);

    if ((mouse_pos.x >= box_size_x(wnd, leave_spt.left) && mouse_pos.x <=
        (box_size_x(wnd, leave_spt.left) + box_size_x(wnd, leave_spt.width)))
        && (mouse_pos.y >= box_size_y(wnd, leave_spt.top) && mouse_pos.y <=
        (box_size_y(wnd, leave_spt.top) + box_size_y(wnd, leave_spt.height)))) {
        if (button->enable_click == TRUE) {
            sfRenderWindow_drawSprite(wnd->window,
                                    button->hover_leave_spt, NULL);
            button->end_gm = TRUE;
        } else
            sfRenderWindow_drawSprite(wnd->window,
                                    button->hover_leave_spt, NULL);
    } else
        sfRenderWindow_drawSprite(wnd->window, button->leave_spt, NULL);
}
