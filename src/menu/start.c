/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** start
*/

#include "../../include/func_name.h"

void rect_pegi(rpg_t *rpg)
{
    if (rpg->menu->intro->intro_pegi->offset_pegi <= 8) {
            rpg->menu->intro->intro_pegi->rect_pegi.left =
            rpg->menu->intro->intro_pegi->offset_pegi *
            rpg->menu->intro->intro_pegi->rect_pegi.width;
            rpg->menu->intro->intro_pegi->rect_pegi.top =
            rpg->menu->intro->intro_pegi->line_pegi *
            rpg->menu->intro->intro_pegi->rect_pegi.height;
            rpg->menu->intro->intro_pegi->offset_pegi++;
    }
    if (rpg->menu->intro->intro_pegi->offset_pegi == 8) {
        rpg->menu->intro->intro_pegi->line_pegi++;
        if (rpg->menu->intro->intro_pegi->line_pegi == 3)
            rpg->menu->intro->intro_pegi->line_pegi = 0;
        rpg->menu->intro->intro_pegi->offset_pegi = 0;
    }
}

void background_pegi(rpg_t *rpg)
{
    static float nbr = 0;

    if (nbr > 2.5 && rpg->menu->intro->intro_pegi->wait_pegi == 0) {
        rpg->menu->intro->intro_pegi->offset_pegi += 1;
        rpg->menu->intro->intro_pegi->wait_pegi = 1;
        nbr = 0;
    }
    if (nbr > 0.2 && rpg->menu->intro->intro_pegi->wait_pegi == 1) {
        rect_pegi(rpg);
        nbr = 0;
    }
    sfSprite_setTextureRect(rpg->menu->intro->intro_pegi->pegi_spt,
    rpg->menu->intro->intro_pegi->rect_pegi);
    nbr += rpg->basic->cnf->clk->time_loop;
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->intro->intro_pegi->pegi_spt, NULL);
}

void rect_basil(rpg_t *rpg)
{
    if (rpg->menu->intro->intro_basil->offset_logo <= 8) {
        rpg->menu->intro->intro_basil->rect_logo.left =
        rpg->menu->intro->intro_basil->offset_logo *
        rpg->menu->intro->intro_basil->rect_logo.width;
        rpg->menu->intro->intro_basil->rect_logo.top =
        rpg->menu->intro->intro_basil->line_logo *
        rpg->menu->intro->intro_basil->rect_logo.height;
        rpg->menu->intro->intro_basil->offset_logo++;
    }
    if (rpg->menu->intro->intro_basil->offset_logo == 8) {
        rpg->menu->intro->intro_basil->line_logo++;
        if (rpg->menu->intro->intro_basil->line_logo == 3)
            rpg->menu->intro->intro_basil->line_logo = 0;
        rpg->menu->intro->intro_basil->offset_logo = 0;
    }
}

void move_basil(rpg_t *rpg)
{
    static float nbr = 0;

    if (nbr > 2.5 && rpg->menu->intro->intro_basil->wait_basil == 0) {
        rpg->menu->intro->intro_basil->offset_logo += 1;
        rpg->menu->intro->intro_basil->wait_basil = 1;
        nbr = 0;
    }
    if (nbr > 0.2 && rpg->menu->intro->intro_basil->wait_basil == 1) {
        rect_basil(rpg);
        nbr = 0;
    }
    sfSprite_setTextureRect(rpg->menu->intro->intro_basil->basil_spt,
    rpg->menu->intro->intro_basil->rect_logo);
    nbr += rpg->basic->cnf->clk->time_loop;
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->intro->intro_basil->basil_spt, NULL);
}

void start_actions(rpg_t *rpg)
{
    static float nbr = 0;

    if (nbr >= 0 && nbr < 8.2) {
        move_basil(rpg);
        sound(rpg, 1);
    }
    if (nbr > 8.2 && nbr < 9.5)
        sfRenderWindow_clear(rpg->basic->wnd->my_wnd, sfBlack);
    if (nbr > 10.5 && nbr < 17.7)
        background_pegi(rpg);
    if (nbr > 17.7)
        rpg->menu->status = ON_MENU;
    nbr += rpg->basic->cnf->clk->time_loop;
}