/*
** EPITECH PROJECT, 2021
** change the volume by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** volume_change.c
*/

#include "../../../../include/defender.h"

 void change_vol_up(menu_t *menu)
{
    if (menu->button->enable_click == FALSE &&
        menu->stg->vol->click_up == TRUE) {
        if (menu->stg->vol->offset < 8) {
            menu->tmp_pause = TRUE;
            menu->stg->vol->offset++;
            menu->stg->vol->vol_nbr.left = menu->stg->vol->offset *
            menu->stg->vol->vol_nbr.width;
            menu->stg->vol->level_vol += 10;
        }
        menu->stg->vol->click_up = FALSE;
    }
}

void change_vol_down(menu_t *menu)
{
    if (menu->button->enable_click == FALSE &&
        menu->stg->vol->click_down == TRUE) {
        if (menu->stg->vol->offset > 0) {
            menu->stg->vol->offset--;
            menu->tmp_pause = TRUE;
            menu->stg->vol->vol_nbr.left = menu->stg->vol->offset *
            menu->stg->vol->vol_nbr.width;
            menu->stg->vol->level_vol -= 10;
        }
        menu->stg->vol->click_down = FALSE;
    }
}

