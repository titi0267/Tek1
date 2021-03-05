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
                    "Ressources/My_defender/MenuJeu.png",
                    NULL);
    menu->bgd_spt = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(menu->bgd_spt, menu->bgd_tex, sfFalse);
    sfSprite_setScale(menu->bgd_spt, scale);
}

void game_name(menu_t *menu)
{
    menu->name_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/Text/Dead_island.png",
                            NULL);
    menu->name_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f name_pos = {2300, 50};

    sfSprite_setTexture(menu->name_spt, menu->name_tex, sfFalse);
    sfSprite_setPosition(menu->name_spt, name_pos);
    sfSprite_setScale(menu->name_spt, scale);
}

void setting_bg(menu_t *menu, window_t *wnd)
{
    menu->set_bg_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/MenuSettings.png",
                            NULL);
    menu->set_bg_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_bg_pos = {wnd->scr_size.width, 0};

    sfSprite_setTexture(menu->set_bg_spt, menu->set_bg_tex, sfFalse);
    sfSprite_setPosition(menu->set_bg_spt, setting_bg_pos);
    sfSprite_setScale(menu->set_bg_spt, scale);
}