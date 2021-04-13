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

} window_t;

typedef struct event_s
{

} event_t;

typedef struct cloc_s
{

} cloc_t;

typedef struct fps_s
{

} fps_t;

typedef struct config_s
{
    cloc_t *clk;
    fps_t *fps;
} config_t;

typedef struct basic_s
{
    config_t *cnf;
    event_t *evt;
    window_t *wnd;
} basic_t;

#endif /* !basics */
