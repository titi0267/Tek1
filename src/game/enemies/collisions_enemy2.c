/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** collisions_enemy2
*/

#include "../../../include/func_name.h"

int check_enemy_collision(rpg_t *rpg, int direction, enemy_t *nmi_list, int sub)
{
    int d = enemy_collision(rpg, direction, nmi_list, sub);
    sfColor color;

    if (d != BEHIND && d != COLLISION)
        sfSprite_setColor(rpg->game->in_game->nmi_list->yellow_man, sfWhite);
    if (d == COLLISION)
        return (COLLISION);
    if (d == BEHIND) {
        color.r = 128;
        color.g = 128;
        color.b = 128;
        color.a = 80;
        sfSprite_setColor(nmi_list->yellow_man, color);
    }
    return (0);
}