/*
** EPITECH PROJECT, 2021
** destroy elements by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** destroy.c
*/

#include "../../include/defender.h"

void destroy_volume_tex(volume_t *vol)
{
    sfTexture_destroy(vol->vol_nbr_tex);
    sfTexture_destroy(vol->vol_tex);
    sfTexture_destroy(vol->down_tex);
    sfTexture_destroy(vol->up_tex);
    sfTexture_destroy(vol->hover_down_tex);
    sfTexture_destroy(vol->hover_up_tex);
    sfTexture_destroy(vol->down_click_tex);
    sfTexture_destroy(vol->up_click_tex);
}

void destroy_volume_spt(volume_t *vol)
{
    sfSprite_destroy(vol->vol_spt);
    sfSprite_destroy(vol->vol_nbr_spt);
    sfSprite_destroy(vol->down_spt);
    sfSprite_destroy(vol->hover_down_spt);
    sfSprite_destroy(vol->down_click_spt);
    sfSprite_destroy(vol->up_spt);
    sfSprite_destroy(vol->hover_up_spt);
    sfSprite_destroy(vol->up_click_spt);
}

void destroy_size_stg_tex(settings_t *stg)
{
    sfTexture_destroy(stg->fullscr_tex);
    sfTexture_destroy(stg->hover_fullscr_tex);
    sfTexture_destroy(stg->click_fullscr_tex);
    sfTexture_destroy(stg->medscr_tex);
    sfTexture_destroy(stg->hover_medscr_tex);
    sfTexture_destroy(stg->click_medscr_tex);
}

void destroy_size_stg_spt(settings_t *stg)
{
    sfSprite_destroy(stg->fullscr_spt);
    sfSprite_destroy(stg->hover_fullscr_spt);
    sfSprite_destroy(stg->click_fullscr_spt);
    sfSprite_destroy(stg->medscr_spt);
    sfSprite_destroy(stg->hover_medscr_spt);
    sfSprite_destroy(stg->click_medscr_spt);
}

void destroy_menu_buttons_tex(menu_t *menu)
{
    sfTexture_destroy(menu->bgd_tex);
    sfTexture_destroy(menu->button->play_tex);
    sfTexture_destroy(menu->button->hover_play_tex);
    sfTexture_destroy(menu->button->click_play_tex);
    sfTexture_destroy(menu->button->leave_tex);
    sfTexture_destroy(menu->button->hover_leave_tex);
    sfTexture_destroy(menu->button->click_leave_tex);
    sfTexture_destroy(menu->button->setting_tex);
    sfTexture_destroy(menu->button->hover_setting_tex);
    sfTexture_destroy(menu->button->click_settings_tex);
}

void destroy_menu_buttons_spt(menu_t *menu)
{
    sfSprite_destroy(menu->bgd_spt);
    sfSprite_destroy(menu->button->play_spt);
    sfSprite_destroy(menu->button->hover_play_spt);
    sfSprite_destroy(menu->button->click_play_spt);
    sfSprite_destroy(menu->button->leave_spt);
    sfSprite_destroy(menu->button->hover_leave_spt);
    sfSprite_destroy(menu->button->click_leave_spt);
    sfSprite_destroy(menu->button->setting_spt);
    sfSprite_destroy(menu->button->hover_setting_spt);
    sfSprite_destroy(menu->button->click_setting_spt);
}

void destroy_stg_bg_tex(menu_t *menu)
{
    sfTexture_destroy(menu->set_bg_tex);
    sfTexture_destroy(menu->name_tex);
    sfTexture_destroy(menu->stg->return_tex);
    sfTexture_destroy(menu->stg->hover_return_tex);
    //sfTexture_destroy(menu->stg->click_return_tex);
}

void destroy_stg_bg_spt(menu_t *menu)
{
    sfSprite_destroy(menu->set_bg_spt);
    sfSprite_destroy(menu->name_spt);
    sfSprite_destroy(menu->stg->return_spt);
    sfSprite_destroy(menu->stg->hover_return_spt);
    //sfSprite_destroy(menu->stg->click_return_spt);
}

void destroy_regroup_spt(menu_t *menu)
{
    destroy_menu_buttons_spt(menu);
    destroy_size_stg_spt(menu->stg);
    destroy_volume_spt(menu->stg->vol);
    destroy_stg_bg_spt(menu);
}

void destroy_regroup_tex(core_t *core)
{
    destroy_menu_buttons_tex(core->menu);
    destroy_size_stg_tex(core->menu->stg);
    destroy_volume_tex(core->menu->stg->vol);
    destroy_stg_bg_tex(core->menu);
}

void destroy_struct(core_t *core)
{
    free(core->wnd);
    free(core->menu->button);
    free(core->menu->stg->vol);
    free(core->menu->stg);
    free(core->menu);
    free(core->time);
    free(core);
}

void destroy_all(core_t *core)
{
    destroy_regroup_tex(core);
    destroy_regroup_spt(core->menu);
    sfRenderWindow_destroy(core->wnd->window);
    sfClock_destroy(core->time->clock);
    destroy_struct(core);
}
