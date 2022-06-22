/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** enemy_translate
*/

#include "../../../include/func_name.h"

int move_enemy_up(rpg_t *rpg, enemy_t *nmi_list, int sub, int yes)
{
    if (yes == 1 && check_enemy_collision
    (rpg, UP, rpg->game->in_game->nmi_list, sub) != COLLISION)
        return (0);
    if (check_enemy_collision(rpg, UP, rpg->game->in_game->nmi_list, sub)
    != COLLISION) {
        rect_move_enemy(rpg, UP, nmi_list);
        nmi_list->nmi_pos.y -= 2;
        return (0);
    }
    return (1);
}

int move_enemy_down(rpg_t *rpg, enemy_t *nmi_list, int sub, int yes)
{
    if (yes == 1 && check_enemy_collision
    (rpg, DOWN, rpg->game->in_game->nmi_list, sub) != COLLISION)
        return (0);
    if (check_enemy_collision(rpg, DOWN, rpg->game->in_game->nmi_list, sub)
    != COLLISION) {
        rect_move_enemy(rpg, DOWN, nmi_list);
        nmi_list->nmi_pos.y += 2;
        return (0);
    }
    return (1);
}

int move_enemy_left(rpg_t *rpg, enemy_t *nmi_list, int sub, int yes)
{
    if (yes == 1 && check_enemy_collision
    (rpg, LEFT, rpg->game->in_game->nmi_list, sub) != COLLISION)
        return (0);
    if (yes != 1 && check_enemy_collision
    (rpg, LEFT, rpg->game->in_game->nmi_list, sub) != COLLISION) {
        rect_move_enemy(rpg, LEFT, nmi_list);
        nmi_list->nmi_pos.x -= 2;
        return (0);
    }
    return (1);
}

int move_enemy_right(rpg_t *rpg, enemy_t *nmi_list, int sub, int yes)
{
    if (yes == 1 && check_enemy_collision
    (rpg, RIGHT, rpg->game->in_game->nmi_list, sub) != COLLISION) {
        return (0);
    }
    if (yes != 1 && check_enemy_collision
    (rpg, RIGHT, rpg->game->in_game->nmi_list, sub) != COLLISION) {
        rect_move_enemy(rpg, RIGHT, nmi_list);
        nmi_list->nmi_pos.x += 2;
        return (0);
    }
    return (1);
}
