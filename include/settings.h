/*
** EPITECH PROJECT, 2021
** setting.h
** File description:
** settings
*/

#ifndef settings
#define settings

typedef struct bgd_sound_stg_s
{

} bgd_sound_stg_t;

typedef struct stg_sound_btn_s
{

} stg_sound_btn_t;

typedef struct stg_sound_s
{
    stg_sound_btn_t *snd_btn;
    bgd_sound_stg_t *bgd_stg;
    main_menu_t *main_menu;
} stg_sound_t;

typedef struct bgd_graph_stg_t
{

} bgd_graph_stg_t;

typedef struct graph_btn_s
{
    sfSprite **graphismes;
    sfTexture *empty_square;
    sfTexture *fill_square;
} graph_btn_t;

typedef struct graph_s
{
    graph_btn_t *graph_btn;
    main_menu_t *main_menu;
    bgd_graph_stg_t *graph_bgd;
} graph_t;

typedef struct bgd_control_stg_s
{

} bgd_control_stg_t;

typedef struct control_s
{
    sfText *box;
    char *text;
    sfKeyCode *key_code;
} control_t;

typedef struct key_bind_s
{
    main_menu_t *main_menu;
    bgd_control_stg_t *control_bgd;
    control_t **control;
    int box_clicked;
} key_bind_t;

typedef struct setting_s
{
    stg_sound_t *stg_snd;
    graph_t *graph;
    key_bind_t *key_bnd;
    sfSprite **opt;
    sfSprite **opt_exit;
    int stg_scene;
} setting_t;

#include "menu.h"

#endif /* !settings */
