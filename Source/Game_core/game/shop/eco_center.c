/*
** EPITECH PROJECT, 2021
** economic center by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** eco_center.c
*/

#include "../../../../include/defender.h"

void eco_center_spt(tower_t *tower)
{
    tower->eco_center_tex = sfTexture_createFromFile(
                        "Ressources/tower/eco_center.png",
                        NULL);
    tower->eco_center_spt = sfSprite_create();
    sfVector2f scale = {2, 2};
    sfVector2f eco_center_pos = {1500, 100};

    sfSprite_setTexture(tower->eco_center_spt, tower->eco_center_tex, sfFalse);
    sfSprite_setPosition(tower->eco_center_spt, eco_center_pos);
    sfSprite_setScale(tower->eco_center_spt, scale);
}
