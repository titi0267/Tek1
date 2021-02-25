/*
** EPITECH PROJECT, 2021
** hover button by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** hover_button.c
*/

#include "../../../../include/defender.h"

void hover_play_but(button_t *button)
{
    button->hover_play_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/image/button/Play_on.png",
                        NULL);
    button->hover_play_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {175, 800};

    sfSprite_setTexture(button->hover_play_spt,
                        button->hover_play_tex, sfFalse);
    sfSprite_setPosition(button->hover_play_spt, setting_pos);
    sfSprite_setScale(button->hover_play_spt, scale);
}
