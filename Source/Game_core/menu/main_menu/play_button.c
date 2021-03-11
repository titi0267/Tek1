/*
** EPITECH PROJECT, 2021
** play button by Timohy CONIEL & Tristan HOURTOULLE
** File description:
** play_button.c
*/

#include "../../../../include/defender.h"

void hover_play_but(button_t *button)
{
    button->hover_play_tex = sfTexture_createFromFile(
                        "Ressources/button/menu/play/hover_play.png",
                        NULL);
    button->hover_play_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {175, 800};

    sfSprite_setTexture(button->hover_play_spt,
                        button->hover_play_tex, sfFalse);
    sfSprite_setPosition(button->hover_play_spt, setting_pos);
    sfSprite_setScale(button->hover_play_spt, scale);
}

void button_play(button_t *button)
{
    button->play_tex = sfTexture_createFromFile(
                        "Ressources/button/menu/play/play.png",
                        NULL);
    button->play_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f play_pos = {175, 800};

    sfSprite_setTexture(button->play_spt, button->play_tex, sfFalse);
    sfSprite_setPosition(button->play_spt, play_pos);
    sfSprite_setScale(button->play_spt, scale);
}

void draw_play(menu_t *menu, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect play = sfSprite_getGlobalBounds(menu->button->play_spt);

    if ((mouse_pos.x >= box_size_x(wnd, play.left) && mouse_pos.x <=
        (box_size_x(wnd, play.left) + box_size_x(wnd, play.width))) &&
        (mouse_pos.y >= box_size_y(wnd, play.top) && mouse_pos.y <=
        (box_size_y(wnd, play.top) + box_size_y(wnd, play.height)))) {
        if (menu->button->enable_click == TRUE) {
            sfRenderWindow_drawSprite(wnd->window,
                                    menu->button->click_play_spt, NULL);
            menu->game_bgd = TRUE;
        }
        else
            sfRenderWindow_drawSprite(wnd->window,
                                    menu->button->hover_play_spt, NULL);
        } else
            sfRenderWindow_drawSprite(wnd->window, menu->button->play_spt, NULL);
}

void click_play_but(menu_t *menu)
{
    menu->button->click_play_tex = sfTexture_createFromFile(
                        "Ressources/button/menu/play/click_play.png",
                        NULL);
    menu->button->click_play_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {175, 800};

    sfSprite_setTexture(menu->button->click_play_spt,
                        menu->button->click_play_tex, sfFalse);
    sfSprite_setPosition(menu->button->click_play_spt, setting_pos);
    sfSprite_setScale(menu->button->click_play_spt, scale);
    menu->game_bgd = FALSE;
}
