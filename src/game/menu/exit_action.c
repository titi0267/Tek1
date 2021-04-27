/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** exit_action
*/

#include "../../../include/func_name.h"

void click_on_resume(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE &&
    (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 390)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 465)))) {
        rpg->menu->status = ON_GAME;
    }
}

void click_on_option(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE &&
    (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 500)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 577)))) {
        rpg->menu->status = ON_OPTION_PAUSE;
    }
}

void click_on_quit(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE &&
    (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 614)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 689)))) {
        save_map(rpg);
        rpg->menu->status = ON_MENU;
    }
}