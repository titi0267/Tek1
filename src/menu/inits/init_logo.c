/*
** EPITECH PROJECT, 2021
** init logo
** File description:
** init_logo.c
*/

#include "../../../include/func_name.h"

static void init_rect_logo(rpg_t *rpg)
{
    rpg->menu->intro->intro_basil->rect_logo.left = 0;
    rpg->menu->intro->intro_basil->rect_logo.width = 1920;
    rpg->menu->intro->intro_basil->rect_logo.height = 1080;
    rpg->menu->intro->intro_basil->rect_logo.top = 0;
    rpg->menu->intro->intro_basil->line_logo = 0;
    rpg->menu->intro->intro_basil->offset_logo = 0;
    rpg->menu->intro->intro_basil->wait_basil = 0;
}

void init_logo_spt(rpg_t *rpg)
{
    sfTexture *basil_tex = sfTexture_createFromFile
    ("assets/start/basil.jpg", NULL);

    rpg->menu->intro->intro_basil->basil_spt = sfSprite_create();
    sfSprite_setTexture(rpg->menu->intro->intro_basil->basil_spt,
    basil_tex, sfTrue);
    init_rect_logo(rpg);
}