/*
** EPITECH PROJECT, 2021
** settings button by TImothy CONIEL & Tristan HOURTOULLE
** File description:
** button.c
*/

#include "../../../../include/defender.h"

void setting_button(menu_t *menu, window_t *wnd)
{
    if (sfMouse_getPositionRenderWindow(wnd->window) == sfSprite_getGlobalBounds(wnd->sandwich1)) {
        my_printf("MIAAAAAA\n");
    }
}
