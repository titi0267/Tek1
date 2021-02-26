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
                        "Ressources/My_defender/button/Play_on.png",
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
                        "Ressources/My_defender/button/PLAY.png",
                        NULL);
    button->play_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f play_pos = {175, 800};

    sfSprite_setTexture(button->play_spt, button->play_tex, sfFalse);
    sfSprite_setPosition(button->play_spt, play_pos);
    sfSprite_setScale(button->play_spt, scale);
}

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
