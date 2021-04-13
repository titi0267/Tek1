/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** window
*/

#include "../include/rpg.h"

void event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->basic->wnd->my_wnd,
    &rpg->basic->evt->event))
        if (rpg->basic->evt->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->basic->wnd->my_wnd);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        rpg->status = 1;
}

void inside_open(rpg_t *rpg)
{
    move_clock(rpg->basic->clk);
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