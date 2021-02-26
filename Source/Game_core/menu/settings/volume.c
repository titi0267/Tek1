/*
** EPITECH PROJECT, 2021
** volume by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** volume.c
*/

#include "../../../../include/defender.h"

void volume_spt(button_t *button)
{
    button->vol_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/volume.png",
                        NULL);
    button->vol_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f vol_pos = {2020, 400};

    sfSprite_setTexture(button->vol_spt, button->vol_tex, sfFalse);
    sfSprite_setPosition(button->vol_spt, vol_pos);
    sfSprite_setScale(button->vol_spt, scale);
}