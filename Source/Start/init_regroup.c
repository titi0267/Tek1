/*
** EPITECH PROJECT, 2021
** Initialize all by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** init_regroup.c
*/

#include "../../include/defender.h"

void init(core_t *core)
{
    initialize_wnd(core->wnd);
    init_timer(core->time);
    backgd_menu(core->menu);
    button_play(core->menu->button);
    button_setting(core->menu->button, core->menu);
    game_name(core->menu);
    hover_setting_but(core->menu->button);
    hover_play_but(core->menu->button);
    button_leave(core->menu, core->menu->button);
    setting_bg(core->menu, core->wnd);
    hover_leave_but(core->menu->button);
    medscr_button(core->menu->stg);
    hover_medscr_button(core->menu->stg);
    fullscr_button(core->menu->stg);
    hover_fullscr_button(core->menu->stg);
    volume_spt(core->menu->stg->vol);
    back_to_menu_spt(core->menu);
    hover_back_to_menu_spt(core->menu->stg);
    vol_nbr_spt(core->menu->stg->vol);
    volume_up_spt(core->menu->stg->vol);
    volume_down_spt(core->menu->stg->vol);
    click_play_but(core->menu->button);
    click_setting_but(core->menu->button);
    up_click_spt(core->menu->stg->vol);
    hover_up_spt(core->menu->stg->vol);
    up_click_spt(core->menu->stg->vol);
    hover_down_spt(core->menu->stg->vol);
    down_click_spt(core->menu->stg->vol);
    click_medscr_button(core->menu->stg);
    click_fullscr_button(core->menu->stg);
    click_back_to_menu_spt(core->menu->stg);
    core->menu->scene_one = scene_menu;
    core->menu->scene_two = no_scene;
    core->menu->list = malloc(sizeof(sfSprite *) * 30);
    create_sprite_arr(core->menu);
    core->menu->button->enable_click = FALSE;
}

void return_to_one(menu_t *menu)
{
    menu->bgd_spt = sfSprite_copy(menu->list[0]);
    menu->set_bg_spt = sfSprite_copy(menu->list[1]);
    menu->button->leave_spt = sfSprite_copy(menu->list[2]);
    menu->button->hover_leave_spt = sfSprite_copy(menu->list[3]);
    menu->name_spt = sfSprite_copy(menu->list[4]);
    menu->button->play_spt = sfSprite_copy(menu->list[5]);
    menu->button->hover_play_spt = sfSprite_copy(menu->list[6]);
    menu->button->click_play_spt = sfSprite_copy(menu->list[7]);
    menu->button->setting_spt = sfSprite_copy(menu->list[8]);
    menu->button->hover_setting_spt = sfSprite_copy(menu->list[9]);
    menu->button->click_setting_spt = sfSprite_copy(menu->list[10]);
    menu->button->click_play_spt = sfSprite_copy(menu->list[11]);
    menu->stg->fullscr_spt = sfSprite_copy(menu->list[12]);
    menu->stg->hover_fullscr_spt = sfSprite_copy(menu->list[13]);
    menu->stg->click_fullscr_spt = sfSprite_copy(menu->list[14]);
    menu->stg->medscr_spt = sfSprite_copy(menu->list[15]);
    menu->stg->hover_medscr_spt = sfSprite_copy(menu->list[16]);
    menu->stg->click_medscr_spt = sfSprite_copy(menu->list[17]);
    menu->stg->return_spt = sfSprite_copy(menu->list[18]);
    menu->stg->hover_return_spt = sfSprite_copy(menu->list[19]);
    menu->stg->click_return_spt = sfSprite_copy(menu->list[20]);
    menu->stg->vol->vol_spt = sfSprite_copy(menu->list[21]);
    menu->stg->vol->up_spt = sfSprite_copy(menu->list[22]);
    menu->stg->vol->hover_up_spt = sfSprite_copy(menu->list[23]);
    menu->stg->vol->up_click_spt = sfSprite_copy(menu->list[24]);
    menu->stg->vol->down_spt = sfSprite_copy(menu->list[25]);
    menu->stg->vol->hover_down_spt = sfSprite_copy(menu->list[26]);
    menu->stg->vol->down_click_spt = sfSprite_copy(menu->list[27]);
    menu->stg->vol->vol_nbr_spt = sfSprite_copy(menu->list[28]);
}

void create_sprite_arr(menu_t *menu)
{
    menu->list[0] = sfSprite_copy(menu->bgd_spt);
    menu->list[1] = sfSprite_copy(menu->set_bg_spt);
    menu->list[2] = sfSprite_copy(menu->button->leave_spt);
    menu->list[3] = sfSprite_copy(menu->button->hover_leave_spt);
    menu->list[4] = sfSprite_copy(menu->name_spt);
    menu->list[5] = sfSprite_copy(menu->button->play_spt);
    menu->list[6] = sfSprite_copy(menu->button->hover_play_spt);
    menu->list[7] = sfSprite_copy(menu->button->click_play_spt);
    menu->list[8] = sfSprite_copy(menu->button->setting_spt);
    menu->list[9] = sfSprite_copy(menu->button->hover_setting_spt);
    menu->list[10] = sfSprite_copy(menu->button->click_setting_spt);
    menu->list[11] = sfSprite_copy(menu->button->click_play_spt);
    menu->list[12] = sfSprite_copy(menu->stg->fullscr_spt);
    menu->list[13] = sfSprite_copy(menu->stg->hover_fullscr_spt);
    menu->list[14] = sfSprite_copy(menu->stg->click_fullscr_spt);
    menu->list[15] = sfSprite_copy(menu->stg->medscr_spt);
    menu->list[16] = sfSprite_copy(menu->stg->hover_medscr_spt);
    menu->list[17] = sfSprite_copy(menu->stg->click_medscr_spt);
    menu->list[18] = sfSprite_copy(menu->stg->return_spt);
    menu->list[19] = sfSprite_copy(menu->stg->hover_return_spt);
    menu->list[20] = sfSprite_copy(menu->stg->click_return_spt);
    menu->list[21] = sfSprite_copy(menu->stg->vol->vol_spt);
    menu->list[22] = sfSprite_copy(menu->stg->vol->up_spt);
    menu->list[23] = sfSprite_copy(menu->stg->vol->hover_up_spt);
    menu->list[24] = sfSprite_copy(menu->stg->vol->up_click_spt);
    menu->list[25] = sfSprite_copy(menu->stg->vol->down_spt);
    menu->list[26] = sfSprite_copy(menu->stg->vol->hover_down_spt);
    menu->list[27] = sfSprite_copy(menu->stg->vol->down_click_spt);
    menu->list[28] = sfSprite_copy(menu->stg->vol->vol_nbr_spt);
    menu->list[29] = NULL;
}
