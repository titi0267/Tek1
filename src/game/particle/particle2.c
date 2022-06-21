/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** particle2
*/

#include "../../../include/func_name.h"

void move_xp(rpg_t *rpg)
{
    for (int i = 0; i <= 5; i++)
        rpg->game->in_game->stats->xp_anim[i].y -= 1;
}