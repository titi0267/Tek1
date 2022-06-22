/*
** EPITECH PROJECT, 2021
** init window
** File description:
** init_window.c
*/

#include "../include/func_name.h"

void get_mouse_pos(basic_t *basic)
{
    basic->cnf->mouse =
    sfMouse_getPositionRenderWindow(basic->wnd->my_wnd);
}

void move_clock(cloc_t *clk)
{
    clk->time_loop =
    sfClock_restart(clk->clock).microseconds / 1000000.0;
    clk->time_total += clk->time_loop;
    clk->time_keyboard += clk->time_loop;
    clk->time_menu += clk->time_loop;
    clk->time_tutorial += clk->time_loop;
    clk->time_shortcut += clk->time_loop;
}

void create_window(basic_t *basic)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfVector2i position_window = {0, 0};
    basic->cnf->scr_cnf->fps = 60;

    basic->wnd->my_wnd = sfRenderWindow_create(video_mode,
    "Grand Theft Covid", sfClose, NULL);
    sfRenderWindow_setKeyRepeatEnabled(basic->wnd->my_wnd, sfFalse);
    sfRenderWindow_setPosition(basic->wnd->my_wnd, position_window);
    sfRenderWindow_setFramerateLimit(basic->wnd->my_wnd,
    basic->cnf->scr_cnf->fps);
}