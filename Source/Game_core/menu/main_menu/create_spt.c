/*
** EPITECH PROJECT, 2021
** create sprite menu by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** create_spt.c
*/

#include "../../../../include/defender.h"

void backgd_menu(menu_t *menu)
{
    menu->bgd_tex = sfTexture_createFromFile(
                    "Ressources/My_defender/image/MenuJeu.png",
                    NULL);
    menu->bgd_spt = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(menu->bgd_spt, menu->bgd_tex, sfFalse);
    sfSprite_setScale(menu->bgd_spt, scale);
}

void button_play(button_t *button)
{
    button->play_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/image/button/PLAY.png",
                        NULL);
    button->play_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f play_pos = {175, 800};

    sfSprite_setTexture(button->play_spt, button->play_tex, sfFalse);
    sfSprite_setPosition(button->play_spt, play_pos);
    sfSprite_setScale(button->play_spt, scale);
}

void game_name(menu_t *menu)
{
    menu->name_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/image/Text/Dead_island.png",
                            NULL);
    menu->name_spt = sfSprite_create();
    sfVector2f scale = {0.7f, 0.7f};
    sfVector2f setting_pos = {500, 50};

    sfSprite_setTexture(menu->name_spt, menu->name_tex, sfFalse);
    sfSprite_setPosition(menu->name_spt, setting_pos);
    sfSprite_setScale(menu->name_spt, scale);
}