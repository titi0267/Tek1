/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** destroy_two
*/

#include "../../include/defender.h"

void destroy_menu_buttons_tex(menu_t *menu)
{
    sfTexture_destroy(menu->bgd_tex);
    sfTexture_destroy(menu->button->play_tex);
    sfTexture_destroy(menu->button->hover_play_tex);
    sfTexture_destroy(menu->button->click_play_tex);
    sfTexture_destroy(menu->button->leave_tex);
    sfTexture_destroy(menu->button->hover_leave_tex);
    sfTexture_destroy(menu->button->click_leave_tex);
    sfTexture_destroy(menu->button->setting_tex);
    sfTexture_destroy(menu->button->hover_setting_tex);
    sfTexture_destroy(menu->button->click_settings_tex);
}

void destroy_menu_buttons_spt(menu_t *menu)
{
    sfSprite_destroy(menu->bgd_spt);
    sfSprite_destroy(menu->button->play_spt);
    sfSprite_destroy(menu->button->hover_play_spt);
    sfSprite_destroy(menu->button->click_play_spt);
    sfSprite_destroy(menu->button->leave_spt);
    sfSprite_destroy(menu->button->hover_leave_spt);
    sfSprite_destroy(menu->button->click_leave_spt);
    sfSprite_destroy(menu->button->setting_spt);
    sfSprite_destroy(menu->button->hover_setting_spt);
    sfSprite_destroy(menu->button->click_setting_spt);
}

void destroy_stg_bg_tex(menu_t *menu)
{
    sfTexture_destroy(menu->set_bg_tex);
    sfTexture_destroy(menu->name_tex);
    sfTexture_destroy(menu->stg->return_tex);
    sfTexture_destroy(menu->stg->hover_return_tex);
}

void destroy_stg_bg_spt(menu_t *menu)
{
    sfSprite_destroy(menu->set_bg_spt);
    sfSprite_destroy(menu->name_spt);
    sfSprite_destroy(menu->stg->return_spt);
    sfSprite_destroy(menu->stg->hover_return_spt);
}