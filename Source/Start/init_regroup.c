/*
** EPITECH PROJECT, 2021
** Initialize all by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** init_regroup.c
*/

#include "../../include/defender.h"

void init_settings_spt(core_t *core)
{
    setting_bg(core->menu, core->wnd);
    medscr_button(core->menu->stg);
    hover_medscr_button(core->menu->stg);
    fullscr_button(core->menu->stg);
    hover_fullscr_button(core->menu->stg);
    volume_spt(core->menu->stg->vol);
    back_to_menu_spt(core->menu);
    hover_back_to_menu_spt(core->menu->stg);
    vol_nbr_spt(core->menu->stg->vol);
    volume_up_spt(core->menu->stg->vol);
    volume_down_spt(core->menu->stg->vol);
    up_click_spt(core->menu->stg->vol);
    hover_up_spt(core->menu->stg->vol);
    up_click_spt(core->menu->stg->vol);
    hover_down_spt(core->menu->stg->vol);
    down_click_spt(core->menu->stg->vol);
    click_medscr_button(core->menu->stg);
    click_fullscr_button(core->menu->stg);
    click_back_to_menu_spt(core->menu->stg);
}

void init_menu_spt(core_t *core)
{
    backgd_menu(core->menu);
    button_play(core->menu->button);
    button_setting(core->menu->button, core->menu);
    game_name(core->menu);
    hover_setting_but(core->menu->button);
    hover_play_but(core->menu->button);
    button_leave(core->menu, core->menu->button);
    hover_leave_but(core->menu->button);
    click_leave_but(core->menu->button);
    click_play_but(core->menu);
    click_setting_but(core->menu->button);
    pause_but(core->game->pause);
}

void init_gm(core_t *core)
{
    game_bgd(core->game);
    shop_button(core->shop, core->menu);
    feed_spt(core);
    ice_tower_spt(core->game->tower);
    archer_spt(core->game->tower);
    wizzard_spt(core->game->tower);
    sfSprite_setTextureRect(core->game->tower->wiz_tower_spt, core->game->tower->wiz_rect);
    sfSprite_setTextureRect(core->game->tower->arrow_tower_spt, core->game->tower->archer_rect);
    sfSprite_setTextureRect(core->game->tower->ice_tower_spt, core->game->tower->ice_rect);
    tower_array(core->game);
    fill_pos_def(core->game);
    fill_alrd_build(core->game);
    create_rect_def(core->game->tower);
}

void init(core_t *core)
{
    initialize_wnd(core->wnd);
    init_timer(core->time);
    init_menu_spt(core);
    init_settings_spt(core);
    init_gm(core);
    core->menu->scene_one = scene_menu;
    core->menu->scene_two = no_scene;
    core->menu->button->enable_click = FALSE;
    core->wave->wave = FALSE;
    core->wave->end_wave = FALSE;
    core->wave->pirate_one = 5;
    core->game->lifepoint = 100;
    core->game->nb_spt = 0;
    core->game->life = sfText_create();
}
