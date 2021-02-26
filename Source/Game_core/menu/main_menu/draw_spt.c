/*
** EPITECH PROJECT, 2021
** draw sprite by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** draw_spt.c
*/

#include "../../../../include/defender.h"

void main_menu_draw(menu_t *menu, window_t *wnd)
{
    sfRenderWindow_drawSprite(wnd->window, menu->bgd_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->button->play_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->name_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->set_bg_spt, NULL);
    hover_setting(menu->button, wnd);
    hover_play(menu->button, wnd);
    hover_leave(menu->button, wnd);
}