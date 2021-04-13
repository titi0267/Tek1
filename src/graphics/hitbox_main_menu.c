/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** hitbox_main_menu
*/

#include "../../include/func_name.h"

void hitbox1(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1242)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 292)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1776)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 391)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->main_menu->menu[NEW_GAME], NULL);
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1242)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 391)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1776)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 490)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->main_menu->menu[CONTINUE], NULL);
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1242)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 490.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1776)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 589.5)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->main_menu->menu[TUTORIAL], NULL);
}

void hitbox2(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1242)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 589.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1776)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 688.5)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->main_menu->menu[OPTIONS], NULL);
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1242)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 688.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1776)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 787.5)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->main_menu->menu[QUIT], NULL);
}

void clic1(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1242)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 589.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1776)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 688.5)))
            rpg->status = 5;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1242)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 688.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1776)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 787.5)))
            exit(0);
    }
}
