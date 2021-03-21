/*
** EPITECH PROJECT, 2021
** destroy elements by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** destroy.c
*/

#include "../../include/defender.h"

void destroy_regroup_spt(core_t *core)
{
    destroy_menu_buttons_spt(core->menu);
    destroy_size_stg_spt(core->menu->stg);
    destroy_volume_spt(core->menu->stg->vol);
    destroy_stg_bg_spt(core->menu);
    destroy_shop_spt(core->shop);
}

void destroy_regroup_tex(core_t *core)
{
    destroy_menu_buttons_tex(core->menu);
    destroy_size_stg_tex(core->menu->stg);
    destroy_volume_tex(core->menu->stg->vol);
    destroy_stg_bg_tex(core->menu);
    destroy_shop_tex(core->shop);
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
    destroy_regroup_spt(core);
    sfRenderWindow_destroy(core->wnd->window);
    sfClock_destroy(core->time->clock);
    destroy_struct(core);
}
