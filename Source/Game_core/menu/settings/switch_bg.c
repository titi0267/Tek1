/*
** EPITECH PROJECT, 2021
** switch background by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** switch_bg.c
*/

#include "../../../../include/defender.h"

void switch_next(menu_t *menu, pause_t *pause)
{
    if (sfSprite_getGlobalBounds(menu->bgd_spt).left >= 0 &&
        menu->pause_on == FALSE && menu->game_bgd == FALSE) {
        menu->menu_bg = TRUE;
        menu->return_to_menu = FALSE;
    } else if (menu->pause_on == TRUE &&
                sfSprite_getGlobalBounds(menu->set_bg_spt).left >= 1920) {
        menu->pause_on = FALSE;
        menu->return_to_menu = FALSE;
        menu->game_bgd = TRUE;
    }
    if (sfSprite_getGlobalBounds(menu->set_bg_spt).left <= 0
        && menu->pause_on == FALSE) {
        menu->settings = TRUE;
        menu->go_to_stg = FALSE;
    } else if (sfSprite_getGlobalBounds(menu->set_bg_spt).left <= 0
                && menu->pause_on == TRUE) {
        menu->go_to_stg = FALSE;
        menu->game_bgd = FALSE;
    }
}

void switch_bg(menu_t *menu, pause_t *pause)
{
    if (menu->settings == FALSE && menu->go_to_stg == TRUE) {
        mv_to_stg_all(menu, pause);
    } else if (menu->menu_bg == FALSE && menu->return_to_menu == TRUE) {
        mv_menu_all(menu, pause);
    }
    switch_next(menu, pause);
}
