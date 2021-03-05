/*
** EPITECH PROJECT, 2021
** volume by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** volume.c
*/

#include "../../../../include/defender.h"

void volume_spt(volume_t *vol)
{
    vol->vol_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/sound_img.png",
                        NULL);
    vol->vol_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f vol_pos = {2020, 513};

    sfSprite_setTexture(vol->vol_spt, vol->vol_tex, sfFalse);
    sfSprite_setPosition(vol->vol_spt, vol_pos);
    sfSprite_setScale(vol->vol_spt, scale);
}

void vol_nbr_spt(volume_t *vol)
{
    vol->vol_nbr_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/Text/Number.png",
                        NULL);
    vol->vol_nbr_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f vol_nbr_pos = {2240, 540};

    sfSprite_setTexture(vol->vol_nbr_spt, vol->vol_nbr_tex, sfFalse);
    sfSprite_setPosition(vol->vol_nbr_spt, vol_nbr_pos);
    sfSprite_setScale(vol->vol_nbr_spt, scale);
    vol->vol_nbr.left = 72 * 4;
    vol->vol_nbr.top = 0;
    vol->vol_nbr.width = 72;
    vol->vol_nbr.height = 146;
    vol->offset = 4;
    vol->width_backup = vol->vol_nbr.width;
}

