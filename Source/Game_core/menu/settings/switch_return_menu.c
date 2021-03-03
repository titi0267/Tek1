/*
** EPITECH PROJECT, 2021
** switch background to initial menu by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** switch_return_menu.c
*/

#include "../../../../include/defender.h"

void settings_spt(menu_t *menu, window_t *wnd)
{
    sfRenderWindow_drawSprite(wnd->window, menu->set_bg_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->bgd_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->name_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->button->play_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->button->setting_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->medscr_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->fullscr_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->vol_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->return_spt, NULL);
    sfSprite_setTextureRect(menu->stg->vol->vol_nbr_spt, menu->stg->vol->vol_nbr);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->vol_nbr_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->down_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->up_spt, NULL);
}
