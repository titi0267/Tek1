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
    button_setting(core->menu->button);
    game_name(core->menu);
    hover_setting_but(core->menu->button);
    hover_play_but(core->menu->button);
    button_leave(core->menu, core->menu->button);
    hover_leave_but(core->menu->button);
}