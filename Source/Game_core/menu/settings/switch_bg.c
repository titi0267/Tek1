/*
** EPITECH PROJECT, 2021
** switch background by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** switch_bg.c
*/

#include "../../../../include/defender.h"

void switch_bg(menu_t *menu)
{
    if (menu->settings == FALSE && menu->go_to_stg == TRUE)
        mv_to_stg_all(menu);
    else if (menu->menu_bg == FALSE && menu->return_to_menu == TRUE)
        mv_menu_all(menu);
    if (sfSprite_getGlobalBounds(menu->bgd_spt).left >= 0) {
        menu->menu_bg = TRUE;
        menu->return_to_menu = FALSE;
    }
    if (sfSprite_getGlobalBounds(menu->set_bg_spt).left <= 0 && menu->pause_on == FALSE) {
        menu->settings = TRUE;
        menu->go_to_stg = FALSE;
    } else if (sfSprite_getGlobalBounds(menu->set_bg_spt).left <= 0 && menu->pause_on == TRUE) {
        menu->go_to_stg = FALSE;
        menu->game_bgd = FALSE;
    }
}
