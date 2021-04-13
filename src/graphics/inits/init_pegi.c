/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_pegi
*/

#include "../../../include/func_name.h"

void init_rect_pegi(rpg_t *rpg)
{
    rpg->main_menu->rect_pegi.left = 0;
    rpg->main_menu->rect_pegi.width = 1920;
    rpg->main_menu->rect_pegi.height = 1080;
    rpg->main_menu->rect_pegi.top = 0;
    rpg->main_menu->line_pegi = 0;
    rpg->main_menu->offset_pegi = 0;
}

void init_pegi_spt(rpg_t *rpg)
{
    sfTexture *pegi_tex = sfTexture_createFromFile
    ("assets/start/pegi.png", NULL);

    rpg->main_menu->pegi_spt = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->pegi_spt,
    pegi_tex, sfTrue);
    rpg->main_menu->wait_pegi = 0;
    init_rect_pegi(rpg);
}