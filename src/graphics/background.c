 /*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** background
*/

#include "../../include/func_name.h"

void rect_adn(rpg_t *rpg)
{
    if (rpg->main_menu->offset == 8) {
        rpg->main_menu->line_rect++;
        if (rpg->main_menu->line_rect == 3)
            rpg->main_menu->line_rect = 0;
        rpg->main_menu->offset = 0;
    }
}

int background(rpg_t *rpg)
{
    static float nbr = 0;

    if (nbr > 0.12) {
        if (rpg->main_menu->offset <= 8) {
            rpg->main_menu->rect_but.left = rpg->main_menu->offset *
            rpg->main_menu->rect_but.width;
            rpg->main_menu->rect_but.top = rpg->main_menu->line_rect *
            rpg->main_menu->rect_but.height;
            rpg->main_menu->offset++;
        }
        rect_adn(rpg);
        nbr = 0;
    }
    sfSprite_setTextureRect(rpg->main_menu->background,
    rpg->main_menu->rect_but);
    nbr += rpg->basic->cnf->clk->time_loop;
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->main_menu->background, NULL);
}