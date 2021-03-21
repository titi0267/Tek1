/*
** EPITECH PROJECT, 2021
** draw scene by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** draw_scene.c
*/

#include "../../include/defender.h"

void select_scene_bis(menu_t *menu)
{
    if (menu->game_bgd == TRUE && menu->shop_bgd == TRUE
        && menu->pause_on == FALSE) {
        menu->scene_one = scene_game;
        menu->scene_two = scene_shop;
    } else if (menu->game_bgd == TRUE && menu->pause_on == TRUE) {
        menu->scene_one = scene_game;
        menu->scene_two = scene_pause;
    }
    if (menu->game_bgd == FALSE && menu->pause_on == TRUE
        && menu->go_to_stg == FALSE) {
        menu->scene_one = scene_pause;
        menu->scene_two = no_scene;
    }
}

void select_scene(menu_t *menu)
{
    if (menu->menu_bg == TRUE && menu->game_bgd == FALSE
        && menu->pause_on == FALSE) {
        menu->scene_one = scene_menu;
        menu->scene_two = no_scene;
    } else if (menu->settings == TRUE && menu->game_bgd == FALSE
        && menu->pause_on == FALSE) {
        menu->scene_one = scene_settings;
        menu->scene_two = no_scene;
    }
    if (menu->settings == FALSE && menu->menu_bg == FALSE &&
        menu->game_bgd == FALSE && menu->pause_on == FALSE) {
        menu->scene_one = scene_settings;
        menu->scene_two = scene_menu;
    } else if (menu->game_bgd == TRUE && menu->shop_bgd == FALSE
        && menu->pause_on == FALSE) {
        menu->scene_one = scene_game;
        menu->scene_two = no_scene;
    } else
        select_scene_bis(menu);
}

void print_scene_bis(menu_t *menu, window_t *wnd, game_t *game, core_t *core)
{
    if (menu->scene_one == scene_game
        && menu->scene_two == no_scene) {
        draw_game(game, wnd, core);
        pause_click(game->pause, wnd, core);
    } else if (menu->scene_one == scene_game
        && menu->scene_two == scene_shop) {
        draw_game(game, wnd, core);
        draw_shop(core, wnd);
        pause_click(game->pause, wnd, core);
    }
    if (menu->scene_one == scene_game
        && menu->scene_two == scene_pause) {
        draw_game(game, wnd, core);
        pause_click(game->pause, wnd, core);
        draw_pause(game->pause, wnd, core);
    } else if (menu->scene_one == scene_pause
        && menu->scene_two == no_scene) {
        draw_pause(game->pause, wnd, core);
    }
}

void print_scene(menu_t *menu, window_t *wnd, game_t *game, core_t *core)
{
    select_scene(menu);
    if (menu->scene_one == scene_menu && menu->scene_two == no_scene) {
        draw_menu(menu, wnd);
    } else if (menu->scene_one == scene_settings
        && menu->scene_two == no_scene) {
        draw_settings(menu, wnd);
    }
    if (menu->scene_one == scene_settings &&
        menu->scene_two == scene_menu) {
        draw_menu(menu, wnd);
        draw_settings(menu, wnd);
    } else if (menu->scene_one == scene_menu &&
                menu->scene_two == scene_settings) {
        draw_settings(menu, wnd);
        draw_menu(menu, wnd);
    } else
        print_scene_bis(menu, wnd, game, core);
}
