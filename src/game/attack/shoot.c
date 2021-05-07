/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** bullet_shoot
*/

#include "../../../include/func_name.h"

void shoot_bullet(rpg_t *rpg)
{
    static float time = 0;

    time += rpg->basic->cnf->clk->time_loop;
    if (/*((*/(rpg->basic->evt->event.type == sfEvtMouseButtonPressed) &&
    /*(rpg->basic->cnf->mouse.x) <= adapt_x(rpg, 1461)) &&
    ((rpg->basic->cnf->mouse.y) <= adapt_y(rpg, 131)) &&
    (rpg->basic->cnf->mouse.x >= adapt_x(rpg, 1478)) &&
    (rpg->basic->cnf->mouse.y >= adapt_y(rpg, 156)) &&*/
    (rpg->game->in_game->inventory->area_contains[WEAPON] == SMG ||
    rpg->game->in_game->inventory->area_contains[WEAPON] == GUN) &&
    !on_cine(rpg) && time >= 0.2) {
        init_bullet(rpg);
        time = 0;
    }
    draw_bullet(rpg);
}