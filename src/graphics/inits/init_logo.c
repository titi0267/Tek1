/*
** EPITECH PROJECT, 2021
** init logo
** File description:
** init_logo.c
*/

#include "../../../include/func_name.h"

void init_rect_logo(rpg_t *rpg)
{
    rpg->main_menu->rect_logo.left = 0;
    rpg->main_menu->rect_logo.width = 1920;
    rpg->main_menu->rect_logo.height = 1080;
    rpg->main_menu->rect_logo.top = 0;
    rpg->main_menu->line_logo = 0;
    rpg->main_menu->offset_logo = 0;
    rpg->main_menu->wait_basil = 0;
}

void init_logo_spt(rpg_t *rpg)
{
    sfTexture *basil_tex = sfTexture_createFromFile
    ("assets/start/basil.png", NULL);

    rpg->main_menu->basil_spt = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->basil_spt,
    basil_tex, sfTrue);
    init_rect_logo(rpg);
}