/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto
*/

#include "../../../include/func_name.h"

void tuto5(rpg_t *rpg)
{
    if (rpg->tutorial->tutorial_stat == TUTO5) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->tutorial->instruct[TUTO5], NULL);
    }
}

void tuto4(rpg_t *rpg)
{
    if (rpg->tutorial->tutorial_stat == TUTO4) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->tutorial->instruct[TUTO4], NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1584.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 918.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1876.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 1006.5)))) {
            rpg->tutorial->tutorial_stat = TUTO5;
            rpg->basic->cnf->clk->time_tutorial = 0;
        }
    }
    tuto5(rpg);
}

void tuto3(rpg_t *rpg)
{
    if (rpg->tutorial->tutorial_stat == TUTO3) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->tutorial->instruct[TUTO3], NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE &&
        rpg->basic->cnf->clk->time_tutorial >= 0.2 &&
        (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1584.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 918.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1876.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 1006.5)))) {
            rpg->tutorial->tutorial_stat = TUTO4;
            rpg->basic->cnf->clk->time_tutorial = 0;
        }
    }
    tuto4(rpg);
}

void tuto2(rpg_t *rpg)
{
    if (rpg->tutorial->tutorial_stat == TUTO2) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->tutorial->instruct[TUTO2], NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE &&
        rpg->basic->cnf->clk->time_tutorial >= 0.2 &&
        (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1584.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 918.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1876.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 1006.5)))) {
            rpg->tutorial->tutorial_stat = TUTO3;
            rpg->basic->cnf->clk->time_tutorial = 0;
        }
    }
    tuto3(rpg);
}

void tuto1(rpg_t *rpg)
{
    tuto_map(rpg);
    enter_car(rpg);
    player_run(rpg);
    if (rpg->tutorial->tutorial_stat == TUTO1) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->tutorial->instruct[TUTO1], NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1584.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 918.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1876.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 1006.5)))) {
            rpg->tutorial->tutorial_stat = TUTO2;
            rpg->basic->cnf->clk->time_tutorial = 0;
        }
    }
    tuto2(rpg);
}