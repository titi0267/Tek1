/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** inventory_manager.c
*/

#include "../../../include/func_name.h"

void detect_weapon2(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1007.5)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1083.5)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5)))
        drag_and_drop(rpg, GUN);
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1098.5)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1174.5)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5)))
        drag_and_drop(rpg, TAZER);
}

void detect_weapon(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 825.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 901.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5)))
            drag_and_drop(rpg, SMG);
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 916.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 992.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5)))
            drag_and_drop(rpg, KNIFE);
        detect_weapon2(rpg);
    }
}