/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** destroy_four
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