/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** enemy_rect
*/

#include "../../../include/func_name.h"

void enemy_stop(rpg_t *rpg)
{
    if (rpg->game->in_game->nmi_list->last_pos != -1) {
        rpg->game->in_game->nmi_list->nmi_rect
        [rpg->game->in_game->nmi_list->last_pos].left = 58;
        sfSprite_setTextureRect(rpg->game->in_game->nmi_list->yellow_man,
        rpg->game->in_game->nmi_list->nmi_rect
        [rpg->game->in_game->nmi_list->last_pos]);
    }
    for (int d = UP; d <=  LEFT; d++) {
        rpg->game->in_game->nmi_list->nmi_rect[d].left = 58;
        rpg->game->in_game->nmi_list->offset_nmi[d] = 0;
    }
}

void rect_move_enemy(rpg_t *rpg, int direction, enemy_t *nmi_list)
{
    if (rpg->game->in_game->nmi_list->clock_rect > 0.2) {
        nmi_list->nmi_rect[direction].left =
        (nmi_list->offset_nmi[direction] *
        nmi_list->nmi_rect[direction].width);
        rpg->game->in_game->nmi_list->clock_rect = 0;
        nmi_list->offset_nmi[direction]++;
    }
    if (nmi_list->offset_nmi[direction] > 2)
        nmi_list->offset_nmi[direction] = 0;
    rpg->game->in_game->nmi_list->clock_rect += rpg->basic->cnf->clk->time_loop;
    rpg->game->in_game->nmi_list->last_pos = direction;
    sfSprite_setTextureRect(rpg->game->in_game->nmi_list->yellow_man,
    rpg->game->in_game->nmi_list->nmi_rect[direction]);
}

void enemy_rect_move_to_player(rpg_t *rpg, enemy_t *nmi_list)
{
    if (nmi_list->diff.x > nmi_list->diff.y &&
    nmi_list->nmi_pos.x >= 960)
        rect_move_enemy(rpg, LEFT, nmi_list);
    if (nmi_list->diff.x > nmi_list->diff.y &&
    nmi_list->nmi_pos.x < 960)
        rect_move_enemy(rpg, RIGHT, nmi_list);
    if (nmi_list->diff.x < nmi_list->diff.y &&
    nmi_list->nmi_pos.y < 535)
        rect_move_enemy(rpg, DOWN, nmi_list);
    if (nmi_list->diff.x < nmi_list->diff.y &&
    nmi_list->nmi_pos.y >= 535)
        rect_move_enemy(rpg, UP, nmi_list);
}

void detect_player(rpg_t *rpg)
{
    rpg->game->in_game->nmi_list->diff
    = vect_diff(rpg->game->in_game->nmi_list->nmi_pos,
    put_in_vector2f(930, 486));
    if (rpg->game->in_game->nmi_list->diff.x < 0)
        rpg->game->in_game->nmi_list->diff.x *= -1;
    if (rpg->game->in_game->nmi_list->diff.y < 0)
        rpg->game->in_game->nmi_list->diff.y *= -1;
    if (rpg->game->in_game->nmi_list->diff.x < 300 &&
    rpg->game->in_game->nmi_list->diff.y < 300)
        enemy_rect_move_to_player(rpg, rpg->game->in_game->nmi_list);
    else
        enemy_stop(rpg);
}
