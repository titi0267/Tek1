/*
** EPITECH PROJECT, 2021
** move to settings by Timothy CONIEL
** File description:
** switch between settings & menu
*/

#include "../../../../../include/defender.h"

void mv_stg_five(menu_t *menu, sfVector2f pos)
{
    pos.x = sfSprite_getGlobalBounds(menu->button->play_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->play_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->button->play_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->hover_play_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->hover_play_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->button->hover_play_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->click_play_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->click_play_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->button->click_play_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->setting_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->setting_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->button->setting_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->hover_setting_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->hover_setting_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->button->hover_setting_spt, pos);
}

void mv_stg_six(menu_t *menu, sfVector2f pos)
{
    pos.x = sfSprite_getGlobalBounds(menu->button->leave_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->leave_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->button->leave_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->hover_leave_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->hover_leave_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->button->hover_leave_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->click_leave_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->click_leave_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->button->click_leave_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->name_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->name_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->name_spt, pos);
}

sfVector2f mv_to_stg_six(sfVector2f pos, pause_t *pause)
{
    pos.x = sfSprite_getGlobalBounds(pause->play_spt).left;
    pos.y = sfSprite_getGlobalBounds(pause->play_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(pause->play_spt, pos);
    pos.x = sfSprite_getGlobalBounds(pause->play_click_spt).left;
    pos.y = sfSprite_getGlobalBounds(pause->play_click_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(pause->play_click_spt, pos);
    pos.x = sfSprite_getGlobalBounds(pause->leave_click_spt).left;
    pos.y = sfSprite_getGlobalBounds(pause->leave_click_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(pause->leave_click_spt, pos);
    pos.x = sfSprite_getGlobalBounds(pause->leave_spt).left;
    pos.y = sfSprite_getGlobalBounds(pause->leave_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(pause->leave_spt, pos);
    pos.x = sfSprite_getGlobalBounds(pause->leave_hover_spt).left;
    pos.y = sfSprite_getGlobalBounds(pause->leave_hover_spt).top;
    pos.x -= 20;
    return (pos);
}

sfVector2f mv_to_stg_all_bis(sfVector2f pos, pause_t *pause)
{
    pos = mv_to_stg_six(pos, pause);
    sfSprite_setPosition(pause->leave_hover_spt, pos);
    pos.x = sfSprite_getGlobalBounds(pause->play_hover_spt).left;
    pos.y = sfSprite_getGlobalBounds(pause->play_hover_spt).top;
    pos.x -= 20;
    return (pos);
}

void mv_to_stg_all(menu_t *menu, pause_t *pause)
{
    sfVector2f pos = {0, 0};

    if (menu->pause_on == TRUE) {
        pos = mv_to_stg_all_bis(pos, pause);
        sfSprite_setPosition(pause->play_hover_spt, pos);
    }
    pos.x = sfSprite_getGlobalBounds(menu->bgd_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->bgd_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->bgd_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->set_bg_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->set_bg_spt).top;
    pos.x -= 20;
    sfSprite_setPosition(menu->set_bg_spt, pos);
    mv_stg_six(menu, pos);
    mv_stg_five(menu, pos);
    mv_stg_four(menu, pos);
    mv_stg_three(menu, pos);
    mv_stg_two(menu, pos);
    mv_stg_one(menu, pos);
}