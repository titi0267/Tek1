/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** draw_scene_bis
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
    sfSprite_setTextureRect(game->tower->arrow_tower_spt,
                            game->tower->archer_rect);
    sfSprite_setTextureRect(game->tower->eco_center_spt, game->tower->eco_rect);
    sfSprite_setTextureRect(game->tower->ice_tower_spt, game->tower->ice_rect);
    sfSprite_setTextureRect(game->tower->def_list[0], game->tower->ice_rect);
    sfSprite_setTextureRect(game->tower->def_list[1],
                            game->tower->archer_rect);
    sfSprite_setTextureRect(game->tower->def_list[2], game->tower->wiz_rect);
    sfSprite_setTextureRect(game->tower->def_list[3], game->tower->eco_rect);
    manage_enemy(core);
    click_shop(core->shop, core->wnd, core->menu);
    eco_placed(core);
    if (game->init_def == TRUE)
        print_def(game, wnd);
}

void draw_shop_bis(core_t *core, window_t *wnd)
{
    get_spt_mouse(core->game->tower, wnd);
    calc_vector(core->game, core->menu);
    if ((core->game->tower->tower_release == TRUE) &&
        (core->menu->button->enable_click == TRUE &&
        core->game->valid == TRUE)) {
        core->game->tower->tower_click = FALSE;
        sfRenderWindow_setMouseCursorVisible(wnd->window, TRUE);
        add_def(core->game);
        core->game->valid = FALSE;
    }
    if ((core->game->tower->tower_release == TRUE) &&
        (core->menu->button->enable_click == TRUE &&
        core->game->valid == FALSE)) {
        core->game->tower->tower_click = FALSE;
        sfRenderWindow_setMouseCursorVisible(wnd->window, TRUE);
        core->game->tower->tower_release = FALSE;
    }
    if (core->menu->button->enable_click == FALSE) {
        core->game->tower->tower_release = TRUE;
    }
}

void draw_shop(core_t *core, window_t *wnd)
{
    if (core->game->tower->tower_click == FALSE) {
        click_ice_tower(wnd, core->menu, core->game->tower);
        click_arrow_tower(wnd, core->menu, core->game->tower);
        click_wiz_tower(wnd, core->menu, core->game->tower);
        click_eco_center(wnd, core->menu, core->game->tower);
    }
    if (core->game->tower->tower_click == TRUE) {
       draw_shop_bis(core, wnd);
    }
}