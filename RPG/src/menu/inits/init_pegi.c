/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_pegi
*/

#include "../../../include/func_name.h"

static void init_rect_pegi(rpg_t *rpg)
{
    rpg->menu->intro->intro_pegi->rect_pegi.left = 0;
    rpg->menu->intro->intro_pegi->rect_pegi.width = 1920;
    rpg->menu->intro->intro_pegi->rect_pegi.height = 1080;
    rpg->menu->intro->intro_pegi->rect_pegi.top = 0;
    rpg->menu->intro->intro_pegi->line_pegi = 0;
    rpg->menu->intro->intro_pegi->offset_pegi = 0;
}

void init_pegi_spt(rpg_t *rpg)
{
    sfTexture *pegi_tex = sfTexture_createFromFile
    ("assets/start/pegi.png", NULL);

    rpg->menu->intro->intro_pegi->pegi_spt = sfSprite_create();
    sfSprite_setTexture(rpg->menu->intro->intro_pegi->pegi_spt,
    pegi_tex, sfTrue);
    rpg->menu->intro->intro_pegi->wait_pegi = 0;
    init_rect_pegi(rpg);
}