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
}