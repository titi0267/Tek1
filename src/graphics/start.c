/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** start
*/

#include "../../include/rpg.h"

void rect_pegi(rpg_t *rpg)
{
    if (rpg->main_menu->offset_pegi <= 8) {
            rpg->main_menu->rect_pegi.left = rpg->main_menu->offset_pegi *
            rpg->main_menu->rect_pegi.width;
            rpg->main_menu->rect_pegi.top = rpg->main_menu->line_pegi *
            rpg->main_menu->rect_pegi.height;
            rpg->main_menu->offset_pegi++;
    }
    if (rpg->main_menu->offset_pegi == 8) {
        rpg->main_menu->line_pegi++;
        if (rpg->main_menu->line_pegi == 3)
            rpg->main_menu->line_pegi = 0;
        rpg->main_menu->offset_pegi = 0;
    }
}

void background_pegi(rpg_t *rpg)
{
    static float nbr = 0;

    if (nbr > 2.5 && rpg->main_menu->wait_pegi == 0) {
        rpg->main_menu->offset_pegi += 1;
        rpg->main_menu->wait_pegi = 1;
        nbr = 0;
    }
    if (nbr > 0.2 && rpg->main_menu->wait_pegi == 1) {
        rect_pegi(rpg);
        nbr = 0;
    }
    sfSprite_setTextureRect(rpg->main_menu->pegi_spt,
    rpg->main_menu->rect_pegi);
    nbr += rpg->basics->time_loop;
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->pegi_spt, NULL);
}

void rect_basil(rpg_t *rpg)
{
    if (rpg->main_menu->offset_logo <= 8) {
        rpg->main_menu->rect_logo.left = rpg->main_menu->offset_logo *
        rpg->main_menu->rect_logo.width;
        rpg->main_menu->rect_logo.top = rpg->main_menu->line_logo *
        rpg->main_menu->rect_logo.height;
        rpg->main_menu->offset_logo++;
    }
    if (rpg->main_menu->offset_logo == 8) {
        rpg->main_menu->line_logo++;
        if (rpg->main_menu->line_logo == 3)
            rpg->main_menu->line_logo = 0;
        rpg->main_menu->offset_logo = 0;
    }
}

void move_basil(rpg_t *rpg)
{
    static float nbr = 0;

    if (nbr > 2.5 && rpg->main_menu->wait_basil == 0) {
        rpg->main_menu->offset_logo += 1;
        rpg->main_menu->wait_basil = 1;
        nbr = 0;
    }
    if (nbr > 0.2 && rpg->main_menu->wait_basil == 1) {
        rect_basil(rpg);
        nbr = 0;
    }
    sfSprite_setTextureRect(rpg->main_menu->basil_spt,
    rpg->main_menu->rect_logo);
    nbr += rpg->basics->time_loop;
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->basil_spt, NULL);
}