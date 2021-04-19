/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** window
*/

#include "../include/func_name.h"

void skip_start(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtKeyReleased &&
        rpg->basic->evt->event.key.code == sfKeySpace &&
        rpg->menu->status == ON_BASIL)
        rpg->menu->status = ON_MENU;
}

void event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->basic->wnd->my_wnd,
    &rpg->basic->evt->event)) {
        if (rpg->basic->evt->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->basic->wnd->my_wnd);
        skip_start(rpg);
    }
}

void inside_open(rpg_t *rpg)
{
    move_clock(rpg->basic->cnf->clk);
    get_mouse_pos(rpg->basic);
}

void open_window(rpg_t *rpg)
{
    create_window(rpg->basic);
    while (sfRenderWindow_isOpen(rpg->basic->wnd->my_wnd)) {
        sfRenderWindow_display(rpg->basic->wnd->my_wnd);
        inside_open(rpg);
        event(rpg);
        parsing(rpg);
    }
}