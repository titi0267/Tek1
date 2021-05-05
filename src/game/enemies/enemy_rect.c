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
    if (rpg->game->in_game->nmi_list->clock_rect > 0.1) {
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

int move_enemy_up(rpg_t *rpg, enemy_t *nmi_list, int sub)
{
    if (check_enemy_collision(rpg, UP, rpg->game->in_game->nmi_list, sub)
    != COLLISION) {
        rect_move_enemy(rpg, UP, nmi_list);
        nmi_list->nmi_pos.y -= 2;
        return (0);
    }
    return (1);
}

int move_enemy_down(rpg_t *rpg, enemy_t *nmi_list, int sub)
{
    if (check_enemy_collision(rpg, DOWN, rpg->game->in_game->nmi_list, sub)
    != COLLISION) {
        rect_move_enemy(rpg, DOWN, nmi_list);
        nmi_list->nmi_pos.y += 2;
        return (0);
    }
    return (1);
}
int move_enemy_left(rpg_t *rpg, enemy_t *nmi_list, int sub)
{
    if (check_enemy_collision(rpg, LEFT, rpg->game->in_game->nmi_list, sub)
    != COLLISION) {
        rect_move_enemy(rpg, LEFT, nmi_list);
        nmi_list->nmi_pos.x -= 2;
        return (0);
    }
    return (1);
}

int move_enemy_right(rpg_t *rpg, enemy_t *nmi_list, int sub)
{
    if (check_enemy_collision(rpg, RIGHT, rpg->game->in_game->nmi_list, sub)
    != COLLISION) {
        rect_move_enemy(rpg, RIGHT, nmi_list);
        nmi_list->nmi_pos.x += 2;
        return (0);
    }
    return (1);
}

void enemy_rect_move_to_player(rpg_t *rpg, enemy_t *nmi_list)
{
    int d = 0;

    if ((nmi_list->diff.x >= nmi_list->diff.y &&
    nmi_list->nmi_pos.x >= 960)) {
        d = move_enemy_left(rpg, nmi_list, 0);
        if (d == 1 && nmi_list->nmi_pos.y < 535) {
            move_enemy_down(rpg, nmi_list, 3);
        }
        else if (d == 1 && nmi_list->nmi_pos.y >= 535)
            move_enemy_up(rpg, nmi_list, 3);
    }
    if ((nmi_list->diff.x >= nmi_list->diff.y &&
    nmi_list->nmi_pos.x < 960)) {
        d = move_enemy_right(rpg, nmi_list, 0);
        if (d == 1 && nmi_list->nmi_pos.y < 535)
            move_enemy_down(rpg, nmi_list, 3);
        else if (d == 1 && nmi_list->nmi_pos.y >= 535)
            move_enemy_up(rpg, nmi_list, 3);
    }
    if ((nmi_list->diff.x <= nmi_list->diff.y &&
    nmi_list->nmi_pos.y < 535)) {
        d = move_enemy_down(rpg, nmi_list, 0);
        if (d == 1 && nmi_list->nmi_pos.x < 960)
            move_enemy_right(rpg, nmi_list, 3);
        else if (d == 1 && nmi_list->nmi_pos.x >= 960)
            move_enemy_left(rpg, nmi_list, 3);
    }
    if ((nmi_list->diff.x <= nmi_list->diff.y &&
    nmi_list->nmi_pos.y >= 535)) {
        d = move_enemy_up(rpg, nmi_list, 0);
        if (d == 1 && nmi_list->nmi_pos.x < 960)
            move_enemy_right(rpg, nmi_list, 3);
        else if (d == 1 && nmi_list->nmi_pos.x >= 960)
            move_enemy_left(rpg, nmi_list, 3);
    }
}

void detect_player(rpg_t *rpg)
{
    rpg->game->in_game->nmi_list->diff
    = vect_diff(rpg->game->in_game->nmi_list->nmi_pos,
    put_in_vector2f(960, 535));
    if (rpg->game->in_game->nmi_list->diff.x < 0)
        rpg->game->in_game->nmi_list->diff.x *= -1;
    if (rpg->game->in_game->nmi_list->diff.y < 0)
        rpg->game->in_game->nmi_list->diff.y *= -1;
    if (rpg->game->in_game->nmi_list->diff.x < 300 &&
    rpg->game->in_game->nmi_list->diff.y < 300 &&
    (rpg->game->in_game->nmi_list->diff.y > 2
    || rpg->game->in_game->nmi_list->diff.x > 2)) {
        enemy_rect_move_to_player(rpg, rpg->game->in_game->nmi_list);
        //printf("move x = %f & y = %f\n", rpg->game->in_game->nmi_list->diff.x, rpg->game->in_game->nmi_list->diff.y);
    } else
        enemy_stop(rpg);
}
