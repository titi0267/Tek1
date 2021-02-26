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
    medscr_button(core->menu->button, core->menu);
    fullscr_button(core->menu->button, core->menu);
    volume_spt(core->menu->button);
    back_to_menu_spt(core->menu->button, core->menu);
    hover_back_to_menu_spt(core->menu->button);
}