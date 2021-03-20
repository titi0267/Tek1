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
    draw_play(menu, wnd);
    draw_setting_btn(menu, wnd);
    draw_leave(menu->button, wnd);
}

void draw_settings(menu_t *menu, window_t *wnd)
{
    sfRenderWindow_drawSprite(wnd->window, menu->set_bg_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->name_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->vol_spt, NULL);
    sfSprite_setTextureRect(menu->stg->vol->vol_nbr_spt,
                            menu->stg->vol->vol_nbr);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->vol_nbr_spt, NULL);
    draw_return(menu->stg, menu, wnd);
    print_fullscr(menu->stg, wnd, menu);
    print_medscr(menu->stg, wnd, menu);
    print_up_vol(menu, wnd);
    print_down_vol(menu, wnd);
}

void draw_game(game_t *game, window_t *wnd, core_t *core)
{
    sfRenderWindow_drawSprite(wnd->window, game->game_bgd_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, game->pause->pause_spt, NULL);
    sfSprite_setTextureRect(game->tower->wiz_tower_spt, game->tower->wiz_rect);
    sfSprite_setTextureRect(game->tower->arrow_tower_spt, game->tower->archer_rect);
    sfSprite_setTextureRect(game->tower->ice_tower_spt, game->tower->ice_rect);
    sfSprite_setTextureRect(game->tower->def_list[0], game->tower->ice_rect);
    sfSprite_setTextureRect(game->tower->def_list[1], game->tower->archer_rect);
    sfSprite_setTextureRect(game->tower->def_list[2], game->tower->wiz_rect);
    manage_enemy(core);
    click_shop(core->shop, core->wnd, core->menu);
    print_def(game, wnd);
}

void draw_shop(core_t *core, window_t *wnd)
{
    if (core->game->tower->tower_click == FALSE) {
        click_ice_tower(wnd, core->menu, core->game->tower);
        click_arrow_tower(wnd, core->menu, core->game->tower);
        click_wiz_tower(wnd, core->menu, core->game->tower);
    }
    if (core->game->tower->tower_click == TRUE) {
        get_spt_mouse(core->game->tower, wnd);
        calc_vector(core->game, core->menu);
        if ((core->game->tower->tower_release == TRUE) &&
            (core->menu->button->enable_click == TRUE &&
            core->game->valid == TRUE)) {
            core->game->tower->tower_click = FALSE;
            sfRenderWindow_setMouseCursorVisible(wnd->window, TRUE);
            add_def(core->game);
            core->game->valid = FALSE;
        } else if ((core->game->tower->tower_release == TRUE) &&
            (core->menu->button->enable_click == TRUE &&
            core->game->valid == FALSE)) {
            core->game->tower->tower_click = FALSE;
            sfRenderWindow_setMouseCursorVisible(wnd->window, TRUE);
            core->game->tower->tower_release = FALSE;
        }
        if (core->menu->button->enable_click == FALSE)
            core->game->tower->tower_release = TRUE;
    }
}

void select_scene(menu_t *menu)
{
    if (menu->menu_bg == TRUE && menu->game_bgd == FALSE && menu->pause_on == FALSE) {
        menu->scene_one = scene_menu;
        menu->scene_two = no_scene;
    } else if (menu->settings == TRUE && menu->game_bgd == FALSE && menu->pause_on == FALSE) {
        menu->scene_one = scene_settings;
        menu->scene_two = no_scene;
    } else if (menu->settings == FALSE && menu->menu_bg == FALSE &&
            menu->game_bgd == FALSE && menu->pause_on == FALSE) {
        menu->scene_one = scene_settings;
        menu->scene_two = scene_menu;
    } else if (menu->game_bgd == TRUE && menu->shop_bgd == FALSE && menu->pause_on == FALSE) {
        menu->scene_one = scene_game;
        menu->scene_two = no_scene;
    } else if (menu->game_bgd == TRUE && menu->shop_bgd == TRUE && menu->pause_on == FALSE) {
        menu->scene_one = scene_game;
        menu->scene_two = scene_shop;
    } else if (menu->game_bgd == TRUE && menu->pause_on == TRUE) {
        menu->scene_one = scene_game;
        menu->scene_two = scene_pause;
    } else if (menu->game_bgd == FALSE && menu->pause_on == TRUE && menu->go_to_stg == FALSE) {
        menu->scene_one = scene_pause;
        menu->scene_two = no_scene;
    }
}

void print_scene(menu_t *menu, window_t *wnd, game_t *game, core_t *core)
{
    select_scene(menu);
    if (menu->scene_one == scene_menu && menu->scene_two == no_scene) {
        draw_menu(menu, wnd);
    } else if (menu->scene_one == scene_settings && menu->scene_two == no_scene) {
        draw_settings(menu, wnd);
    } else if (menu->scene_one == scene_settings &&
            menu->scene_two == scene_menu) {
        draw_menu(menu, wnd);
        draw_settings(menu, wnd);
    } else if (menu->scene_one == scene_menu &&
                menu->scene_two == scene_settings) {
        draw_settings(menu, wnd);
        draw_menu(menu, wnd);
    } else if (menu->scene_one == scene_game && menu->scene_two == no_scene) {
        draw_game(game, wnd, core);
        pause_click(game->pause, wnd, core);
    } else if (menu->scene_one == scene_game && menu->scene_two == scene_shop) {
        draw_game(game, wnd, core);
        draw_shop(core, wnd);
        pause_click(game->pause, wnd, core);
    } else if (menu->scene_one == scene_game && menu->scene_two == scene_pause) {
        draw_game(game, wnd, core);
        pause_click(game->pause, wnd, core);
        draw_pause(game->pause, wnd, core);
    } else if (menu->scene_one == scene_pause && menu->scene_two == no_scene) {
        draw_pause(game->pause, wnd, core);
    }
}
