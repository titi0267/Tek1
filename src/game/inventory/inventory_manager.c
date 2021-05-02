/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** inventory_manager.c
*/

#include "../../../include/func_name.h"
// ARME = 370.5 x 366.5        -       446.5 x 442.5

void detect_weapon2(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1007.5)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1083.5)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5)))
        rpg->game->in_game->inventory->selected_item = GUN;
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1098.5)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1174.5)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5)))
        rpg->game->in_game->inventory->selected_item = TAZER;
}

void detect_weapon(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
    rpg->game->in_game->inventory->selected_item == NO_SLOT) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 825.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 901.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5)))
            rpg->game->in_game->inventory->selected_item = SMG;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 916.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 992.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5)))
            rpg->game->in_game->inventory->selected_item = KNIFE;
        detect_weapon2(rpg);
    }
}