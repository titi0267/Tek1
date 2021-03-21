/*
** EPITECH PROJECT, 2021
** move to settings by Timothy CONIEL
** File description:
** switch between settings & menu
*/

#include "../../../../../include/defender.h"

void mv_menu_five(menu_t *menu, sfVector2f pos)
{
    pos.x = sfSprite_getGlobalBounds(menu->button->click_leave_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->click_leave_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->click_leave_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->name_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->name_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->name_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->play_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->play_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->play_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->hover_play_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->hover_play_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->hover_play_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->click_play_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->click_play_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->click_play_spt, pos);
}

void mv_menu_six(menu_t *menu, sfVector2f pos)
{
    pos.x = sfSprite_getGlobalBounds(menu->bgd_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->bgd_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->bgd_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->set_bg_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->set_bg_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->set_bg_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->leave_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->leave_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->leave_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->hover_leave_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->hover_leave_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->hover_leave_spt, pos);
}

void mv_menu_all(menu_t *menu, pause_t *pause)
{
    sfVector2f pos = {0, 0};

    if (menu->pause_on == TRUE) {
        pos.x = sfSprite_getGlobalBounds(pause->play_spt).left;
        pos.y = sfSprite_getGlobalBounds(pause->play_spt).top;
        pos.x += 20;
        sfSprite_setPosition(pause->play_spt, pos);
        pos.x = sfSprite_getGlobalBounds(pause->play_click_spt).left;
        pos.y = sfSprite_getGlobalBounds(pause->play_click_spt).top;
        pos.x += 20;
        sfSprite_setPosition(pause->play_click_spt, pos);
        pos.x = sfSprite_getGlobalBounds(pause->play_hover_spt).left;
        pos.y = sfSprite_getGlobalBounds(pause->play_hover_spt).top;
        pos.x += 20;
        sfSprite_setPosition(pause->play_hover_spt, pos);
    }
    mv_menu_six(menu, pos);
    mv_menu_five(menu, pos);
    mv_menu_four(menu, pos);
    mv_menu_three(menu, pos);
    mv_menu_two(menu, pos);
    mv_menu_one(menu, pos);
}