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

void volume_up_spt(volume_t *vol)
{
    vol->up_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/up_image.png",
                        NULL);
    vol->up_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f up_pos = {2220, 400};
    sfSprite_setTexture(vol->up_spt, vol->up_tex, sfFalse);
    sfSprite_setPosition(vol->up_spt, up_pos);
    sfSprite_setScale(vol->up_spt, scale);
}

void volume_down_spt(volume_t *vol)
{
    vol->down_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/vol_down_spt.png",
                        NULL);
    vol->down_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f down_pos = {2220, 700};

    sfSprite_setTexture(vol->down_spt, vol->down_tex, sfFalse);
    sfSprite_setPosition(vol->down_spt, down_pos);
    sfSprite_setScale(vol->down_spt, scale);
}
