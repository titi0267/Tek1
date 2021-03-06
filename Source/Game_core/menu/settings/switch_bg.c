/*
** EPITECH PROJECT, 2021
** switch background by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** switch_bg.c
*/

#include "../../../../include/defender.h"

void mv_spt_list(menu_t *menu)
{
    sfVector2f global_pos;

    create_sprite_arr(menu);
    for  (int i = 0; menu->list[i] != NULL; i++) {
        global_pos.x = sfSprite_getGlobalBounds(menu->list[i]).left;
        global_pos.y = sfSprite_getGlobalBounds(menu->list[i]).top;
        global_pos.x -= 20;
        sfSprite_setPosition(menu->list[i], global_pos);
    }
    return_to_one(menu);
}

void mv_spt_return(menu_t *menu)
{
    sfVector2f global_pos;

    create_sprite_arr(menu);
    for  (int i = 0; menu->list[i] != NULL; i++) {
        global_pos.x = sfSprite_getGlobalBounds(menu->list[i]).left;
        global_pos.y = sfSprite_getGlobalBounds(menu->list[i]).top;
        global_pos.x += 20;
        sfSprite_setPosition(menu->list[i], global_pos);
    }
    return_to_one(menu);
}

void switch_bg(menu_t *menu)
{
    if (menu->settings == FALSE && menu->go_to_stg == TRUE)
        mv_spt_list(menu);
    else if (menu->menu_bg == FALSE && menu->return_to_menu == TRUE)
        mv_spt_return(menu);
    if (sfSprite_getGlobalBounds(menu->bgd_spt).left >= 0) {
        menu->menu_bg = TRUE;
        menu->return_to_menu = FALSE;
    }
    if (sfSprite_getGlobalBounds(menu->set_bg_spt).left <= 0) {
        menu->settings = TRUE;
        menu->go_to_stg = FALSE;
    }
}
