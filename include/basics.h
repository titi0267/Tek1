/*
** EPITECH PROJECT, 2021
** basics.h
** File description:
** basics rpg
*/

#ifndef basics
#define basics

#define MALLOC_ERROR 84

typedef struct window_s
{
    sfRenderWindow *my_wnd;
    int win_width;
    int win_height;
} window_t;

typedef struct event_s
{
    sfEvent event;
} event_t;

typedef struct cloc_s
{
    sfClock *clock;
    float time_total;
    float time_loop;
    float time_keyboard;
    float time_menu;
    float time_tutorial;
    float time_shortcut;
    float direction_clk;
    float time_damage;
} cloc_t;

typedef struct screen_conf_s
{
    int fps;
    int resolution;
} screen_conf_t;

typedef struct config_s
{
    cloc_t *clk;
    screen_conf_t *scr_cnf;
    sfVector2i mouse;
} config_t;

#endif /* !basics */
