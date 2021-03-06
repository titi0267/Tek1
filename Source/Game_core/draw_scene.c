/*
** EPITECH PROJECT, 2021
** draw scene by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** draw_scene.c
*/

#include "../../include/defender.h"

void draw_menu(menu_t *menu, window_t *wnd)
{
    sfRenderWindow_drawSprite(wnd->window, menu->bgd_spt, NULL);
    draw_play(menu->button, wnd);
    draw_setting(menu, wnd);
    draw_leave(menu->button, wnd);
}

void draw_settings(menu_t *menu, window_t *wnd)
{
    sfRenderWindow_drawSprite(wnd->window, menu->set_bg_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->name_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->vol_spt, NULL);
    sfSprite_setTextureRect(menu->stg->vol->vol_nbr_spt, menu->stg->vol->vol_nbr);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->vol_nbr_spt, NULL);
    draw_return(menu->stg, menu, wnd);
    print_fullscr(menu->stg, wnd, menu);
    print_medscr(menu->stg, wnd, menu);
    print_up_vol(menu, wnd);
    print_down_vol(menu, wnd);
}

void choose_scene(menu_t *menu, window_t *wnd)
{
    if (menu->menu_bg == TRUE) {
        menu->scene_one = scene_menu;
        menu->scene_two = no_scene;
    } else if (menu->settings == TRUE) {
        menu->scene_one = scene_settings;
        menu->scene_two = no_scene;
    } else if (menu->settings == FALSE && menu->menu_bg == FALSE) {
        menu->scene_one = scene_settings;
        menu->scene_two = scene_menu;
    }



    /*if (menu->return_to_menu == FALSE && menu->settings == TRUE) {
        menu->scene_one = scene_settings;
        menu->scene_two = scene_menu;
    }
    if (menu->settings == TRUE && menu->return_to_menu == TRUE) {
        menu->scene_one = scene_menu;
        menu->scene_two = scene_settings;
    }
    if (menu->menu_bg == FALSE && menu->return_to_menu == FALSE) {
        menu->scene_one = scene_settings;
        menu->scene_two = no_scene;
    }
    else if (menu->menu_bg == TRUE && menu->settings == FALSE && menu->return_to_menu == FALSE) {
        menu->scene_one = scene_menu;
        menu->scene_two = no_scene;
    }*/
    if (menu->scene_one == scene_menu && menu->scene_two == no_scene) {
        draw_menu(menu, wnd);
    }
    if (menu->scene_one == scene_settings && menu->scene_two == no_scene) {
        draw_settings(menu, wnd);
    }
    if (menu->scene_one == scene_settings && menu->scene_two == scene_menu) {
        draw_menu(menu, wnd);
        draw_settings(menu, wnd);
    }
    if (menu->scene_one == scene_menu && menu->scene_two == scene_settings) {
        draw_settings(menu, wnd);
        draw_menu(menu, wnd);
    }
}