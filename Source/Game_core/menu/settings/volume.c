/*
** EPITECH PROJECT, 2021
** volume by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** volume.c
*/

#include "../../../../include/defender.h"

void volume_spt(settings_t *stg)
{
    stg->vol_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/volume.png",
                        NULL);
    stg->vol_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f vol_pos = {2020, 400};

    sfSprite_setTexture(stg->vol_spt, stg->vol_tex, sfFalse);
    sfSprite_setPosition(stg->vol_spt, vol_pos);
    sfSprite_setScale(stg->vol_spt, scale);
}