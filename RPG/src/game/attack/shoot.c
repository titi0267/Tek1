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
    if ((sfTrue == sfKeyboard_isKeyPressed(sfKeyEnter)) &&
    (rpg->game->in_game->inventory->area_contains[WEAPON] == SMG ||
    rpg->game->in_game->inventory->area_contains[WEAPON] == GUN ||
    rpg->game->in_game->inventory->area_contains[WEAPON] == TAZER) &&
    !on_cine(rpg) && time >= 0.2 &&
    rpg->game->in_game->objects->speed_status != CAR_SPEED) {
        init_bullet(rpg);
        time = 0;
    }
    if ((sfTrue == sfKeyboard_isKeyPressed(sfKeyEnter)) &&
    (rpg->game->in_game->inventory->area_contains[WEAPON] == KNIFE ||
    rpg->game->in_game->inventory->area_contains[WEAPON] == NO_WEAPON) &&
    !on_cine(rpg) && time >= 0.5 &&
    rpg->game->in_game->objects->speed_status != CAR_SPEED) {
        draw_knife(rpg);
        for (rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);
        rpg->game->in_game->nmi_list != NULL;
        rpg->game->in_game->nmi_list = rpg->game->in_game->nmi_list->next)
            attack_cut(rpg, rpg->game->in_game->nmi_list);
        time = 0;
    }
    draw_bullet(rpg);
}