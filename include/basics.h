/*
** EPITECH PROJECT, 2021
** basics.h
** File description:
** basics rpg
*/

#ifndef basics
#define basics

typedef struct window_s
{
    sfRenderWindow *my_wnd;
ndow_t;
typedef struct event_s
{

} event_t;

    sfEvent event;typedef struct cloc_s
{

} cloc_t;

    sfClock *clock;
    float time_total;
    float time_loop;typedef struct fps_s
{

} fps_t;src_creen_conf

    int fps;
    int resolution;typedef struct config_s
{screen_conf
    cloc_t *clk;
    fps_t *fps;
} config_t;

typescreen_conf strscr_cnf 
    sfVector2i mouse;basic_s
{
    config_t *cnf;
    event_t *evt;
    window_t *wnd;
} basic_t;

#endif /* !basics */
