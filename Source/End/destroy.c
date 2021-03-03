/*
** EPITECH PROJECT, 2021
** destroy elements by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** destroy.c
*/

#include "../../include/defender.h"

void destroy_tex2(core_t *core)
{
    sfTexture_destroy(core->menu->button->hover_play_tex);
    sfTexture_destroy(core->menu->stg->fullscr_tex);
    sfTexture_destroy(core->menu->stg->hover_fullscr_tex);
    sfTexture_destroy(core->menu->stg->hover_medscr_tex);
    sfTexture_destroy(core->menu->stg->hover_return_tex);
    sfTexture_destroy(core->menu->stg->medscr_tex);
    sfTexture_destroy(core->menu->stg->return_tex);
    sfTexture_destroy(core->menu->stg->vol->vol_nbr_tex);
    sfTexture_destroy(core->menu->stg->vol->vol_tex);
}

void destroy_tex(core_t *core)
{
    sfTexture_destroy(core->menu->bgd_tex);
    sfTexture_destroy(core->menu->button->hover_setting_tex);
    sfTexture_destroy(core->menu->button->setting_tex);
    sfTexture_destroy(core->menu->button->leave_tex);
    sfTexture_destroy(core->menu->button->hover_leave_tex);
    sfTexture_destroy(core->menu->button->play_tex);
    sfTexture_destroy(core->menu->set_bg_tex);
    sfTexture_destroy(core->menu->name_tex);
    destroy_tex2(core);
}
void destroy_spt2(core_t *core)
{
    sfSprite_destroy(core->menu->button->setting_spt);
    sfSprite_destroy(core->menu->button->hover_setting_spt);
    sfSprite_destroy(core->menu->name_spt);
    sfSprite_destroy(core->menu->set_bg_spt);
    sfSprite_destroy(core->menu->button->hover_play_spt);
    sfSprite_destroy(core->menu->stg->fullscr_spt);
    sfSprite_destroy(core->menu->stg->hover_fullscr_spt);
    sfSprite_destroy(core->menu->stg->hover_medscr_spt);
    sfSprite_destroy(core->menu->stg->hover_return_spt);
    sfSprite_destroy(core->menu->stg->medscr_spt);
    sfSprite_destroy(core->menu->stg->return_spt);
    sfSprite_destroy(core->menu->stg->vol->vol_spt);
    sfSprite_destroy(core->menu->stg->vol->vol_nbr_spt);
}

void destroy_spt(core_t *core)
{
    sfSprite_destroy(core->menu->bgd_spt);
    sfSprite_destroy(core->menu->button->play_spt);
    sfSprite_destroy(core->menu->button->leave_spt);
    sfSprite_destroy(core->menu->button->hover_leave_spt);
    destroy_spt2(core);
    for (int i = 0; core->menu->list[i] != NULL; i++)
        sfSprite_destroy(core->menu->list[i]);
}

void destroy1(core_t *core)
{
    destroy_tex(core);
    destroy_spt(core);
    sfRenderWindow_destroy(core->wnd->window);
    sfClock_destroy(core->time->clock);
    free(core->wnd);
    free(core->menu->button);
    free(core->menu->stg->vol);
    free(core->menu->stg);
    free(core->menu);
    free(core->time);
    free(core);
}