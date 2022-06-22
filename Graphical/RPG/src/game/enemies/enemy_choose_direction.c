/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** enemy_choose_direction
*/

#include "../../../include/func_name.h"

static void enemy_move_left_player(rpg_t *rpg, enemy_t *nmi_list)
{
    if (nmi_list->choose_dir == LEFT &&
    move_enemy_left(rpg, nmi_list, 10, 1) != COLLISION)
        move_enemy_left(rpg, nmi_list, 0, 0);
    else if (nmi_list->choose_dir == LEFT &&
    move_enemy_left(rpg, nmi_list, 10, 1) == COLLISION && move_enemy_up
    (rpg, nmi_list, 10, 1) != COLLISION && nmi_list->nmi_pos.y >= 535)
        nmi_list->choose_dir = UP;
    else {
        if (nmi_list->choose_dir == LEFT &&
        move_enemy_left(rpg, nmi_list, 10, 1) == COLLISION && move_enemy_down
        (rpg, nmi_list, 10, 1) != COLLISION && nmi_list->nmi_pos.y < 535)
            nmi_list->choose_dir = DOWN;
        else if (nmi_list->choose_dir == LEFT &&
        move_enemy_left(rpg, nmi_list, 10, 1) == COLLISION
        && move_enemy_right(rpg, nmi_list, 10, 1) != COLLISION) {
            nmi_list->choose_dir = RIGHT;
        }
    }
}

static void enemy_move_right_player(rpg_t *rpg, enemy_t *nmi_list)
{
    if (nmi_list->choose_dir == RIGHT &&
    move_enemy_right(rpg, nmi_list, 10, 1) != COLLISION)
        move_enemy_right(rpg, nmi_list, 0, 0);
    else if (nmi_list->choose_dir == RIGHT &&
    move_enemy_right(rpg, nmi_list, 10, 1) == COLLISION && move_enemy_up
    (rpg, nmi_list, 10, 1) != COLLISION && nmi_list->nmi_pos.y >= 535)
        nmi_list->choose_dir = UP;
    else {
        if (nmi_list->choose_dir == RIGHT &&
        move_enemy_right(rpg, nmi_list, 10, 1) == COLLISION && move_enemy_down
        (rpg, nmi_list, 10, 1) != COLLISION && nmi_list->nmi_pos.y < 535)
            nmi_list->choose_dir = DOWN;
        else if (nmi_list->choose_dir == RIGHT &&
        move_enemy_right(rpg, nmi_list, 10, 1) == COLLISION
        && move_enemy_left(rpg, nmi_list, 10, 1) != COLLISION)
            nmi_list->choose_dir = LEFT;
    }
}

static void enemy_move_up_player(rpg_t *rpg, enemy_t *nmi_list)
{
    if (nmi_list->choose_dir == UP &&
    move_enemy_up(rpg, nmi_list, 10, 1) != COLLISION)
        move_enemy_up(rpg, nmi_list, 0, 0);
    else if (nmi_list->choose_dir == UP &&
    move_enemy_up(rpg, nmi_list, 10, 1) == COLLISION && move_enemy_left
    (rpg, nmi_list, 10, 1) != COLLISION && nmi_list->nmi_pos.x >= 960)
        nmi_list->choose_dir = LEFT;
    else {
        if (nmi_list->choose_dir == UP &&
        move_enemy_up(rpg, nmi_list, 10, 1) == COLLISION && move_enemy_right
        (rpg, nmi_list, 10, 1) != COLLISION && nmi_list->nmi_pos.x < 960)
            nmi_list->choose_dir = RIGHT;
        else if (nmi_list->choose_dir == UP &&
        move_enemy_up(rpg, nmi_list, 10, 1) == COLLISION
        && move_enemy_down(rpg, nmi_list, 10, 1) != COLLISION)
            nmi_list->choose_dir = DOWN;
    }
}
static void enemy_move_down_player(rpg_t *rpg, enemy_t *nmi_list)
{
    if (nmi_list->choose_dir == DOWN &&
    move_enemy_down(rpg, nmi_list, 10, 1) != COLLISION)
        move_enemy_down(rpg, nmi_list, 0, 0);
    else if (nmi_list->choose_dir == DOWN &&
    move_enemy_down(rpg, nmi_list, 10, 1) == COLLISION && move_enemy_left
    (rpg, nmi_list, 10, 1) != COLLISION && nmi_list->nmi_pos.x >= 960)
        nmi_list->choose_dir = LEFT;
    else {
        if (nmi_list->choose_dir == DOWN &&
        move_enemy_down(rpg, nmi_list, 10, 1) == COLLISION && move_enemy_right
        (rpg, nmi_list, 10, 1) != COLLISION && nmi_list->nmi_pos.x < 960)
            nmi_list->choose_dir = RIGHT;
        else if (nmi_list->choose_dir == DOWN &&
        move_enemy_down(rpg, nmi_list, 10, 1) == COLLISION
        && move_enemy_up(rpg, nmi_list, 10, 1) != COLLISION)
            nmi_list->choose_dir = UP;
    }
}

void enemy_rect_move_to_player(rpg_t *rpg, enemy_t *nmi_list)
{
    define_direction(rpg, nmi_list);
    enemy_move_left_player(rpg, nmi_list);
    enemy_move_right_player(rpg, nmi_list);
    enemy_move_down_player(rpg, nmi_list);
    enemy_move_up_player(rpg, nmi_list);
}
