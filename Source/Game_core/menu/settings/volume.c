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
                        "Ressources/My_defender/button/volume.png",
                        NULL);
    vol->vol_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f vol_pos = {2020, 400};

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
    sfVector2f vol_nbr_pos = {2300, 525};

    sfSprite_setTexture(vol->vol_nbr_spt, vol->vol_nbr_tex, sfFalse);
    sfSprite_setPosition(vol->vol_nbr_spt, vol_nbr_pos);
    sfSprite_setScale(vol->vol_nbr_spt, scale);
    vol->vol_nbr.left = 0;
    vol->vol_nbr.top = 0;
    vol->vol_nbr.width = 73.22f;
    vol->vol_nbr.height = 129;
    vol->offset = 0;
}