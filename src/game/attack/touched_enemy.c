/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** touched_enemy
*/

#include "../../../include/func_name.h"

void pop_enemy(rpg_t *rpg, enemy_t *nmi_list)
{
    int del_nbr = nmi_list->nbr;
    enemy_t *nmi_prev = NULL;

    nmi_list = *rpg->game->in_game->nmi;
    if (*rpg->game->in_game->nmi == NULL)
        return;
    while(nmi_list->nbr != del_nbr) {
        if (nmi_list->next == NULL)
            return;
        else {
            nmi_prev = nmi_list;
            nmi_list = nmi_list->next;
        }
    }
    if (nmi_list == *rpg->game->in_game->nmi)
        *(rpg->game->in_game->nmi) = (*rpg->game->in_game->nmi)->next;
    else {
        nmi_prev->next = nmi_list->next;
        nmi_list->next = NULL;
    }
}

void is_touched(rpg_t *rpg, bullets_t *bullet_list, enemy_t *nmi_list)
{
    if ((nmi_list->nmi_pos.x) < bullet_list->bullet_pos.x &&
    (nmi_list->nmi_pos.x + 55) > bullet_list->bullet_pos.x &&
    (nmi_list->nmi_pos.y) < bullet_list->bullet_pos.y &&
    (nmi_list->nmi_pos.y + 88) > bullet_list->bullet_pos.y) {
        nmi_list->life -=
        rpg->game->in_game->stats->player_stats[P_DAMAGE]->value;
        pop_bullet(rpg, bullet_list);
        nmi_list->blooding = 1;
    }
}

void collision_enemy_player(rpg_t *rpg, enemy_t *nmi_list)
{
    if (((nmi_list->nmi_pos.x > 930 && nmi_list->nmi_pos.x < 990) ||
    (nmi_list->nmi_pos.x + 55 > 930 && nmi_list->nmi_pos.x + 55 < 990)) &&
    ((nmi_list->nmi_pos.y > 485 && nmi_list->nmi_pos.y < 593) ||
    (nmi_list->nmi_pos.y > 485 && nmi_list->nmi_pos.y < 593))) {
        rpg->game->in_game->stats->player_stats[P_LIFE]->value -= 10;
    }
}

void collision_enemy_bullet(rpg_t *rpg)
{
    enemy_t *nmi_l_blood;

        for (nmi_l_blood = *(rpg->game->in_game->nmi);
    nmi_l_blood != NULL; nmi_l_blood = nmi_l_blood->next) {
            creat_blood(rpg, nmi_l_blood);
    }
    for (rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);
    rpg->game->in_game->nmi_list != NULL; rpg->game->in_game->nmi_list
    = rpg->game->in_game->nmi_list->next) {
        collision_enemy_player(rpg, rpg->game->in_game->nmi_list);
        if (rpg->game->in_game->nmi_list->life <= 0
        && rpg->game->in_game->nmi_list->blooding == 0) {
            pop_enemy(rpg, rpg->game->in_game->nmi_list);
            rpg->game->in_game->stats->xp_value += 10;
        }
        for (rpg->game->in_game->bullet_list = *(rpg->game->in_game->bullet);
        rpg->game->in_game->bullet_list != NULL; rpg->game->in_game->bullet_list
        = rpg->game->in_game->bullet_list->next) {
            is_touched(rpg, rpg->game->in_game->bullet_list,
            rpg->game->in_game->nmi_list);
        }
    }
}
