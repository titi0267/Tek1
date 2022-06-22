/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** background
*/

#include "../../include/func_name.h"

void rect_adn(rpg_t *rpg)
{
    if (rpg->menu->bgd_adn->offset <= 8) {
        rpg->menu->bgd_adn->rect_background.left =
        rpg->menu->bgd_adn->offset *
        rpg->menu->bgd_adn->rect_background.width;
        rpg->menu->bgd_adn->rect_background.top =
        rpg->menu->bgd_adn->line_rect *
        rpg->menu->bgd_adn->rect_background.height;
        rpg->menu->bgd_adn->offset++;
    }
    if (rpg->menu->bgd_adn->offset == 8) {
        rpg->menu->bgd_adn->line_rect++;
        if (rpg->menu->bgd_adn->line_rect == 3)
            rpg->menu->bgd_adn->line_rect = 0;
        rpg->menu->bgd_adn->offset = 0;
    }
}

void background(rpg_t *rpg)
{
    static float nbr = 0;

    if (nbr > 0.12) {
        rect_adn(rpg);
        nbr = 0;
    }
    sfSprite_setTextureRect(rpg->menu->bgd_adn->background,
    rpg->menu->bgd_adn->rect_background);
    if (rpg->menu->status == ON_MENU)
        nbr += rpg->basic->cnf->clk->time_loop / 2;
    else
        nbr += rpg->basic->cnf->clk->time_loop;
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->bgd_adn->background, NULL);
}