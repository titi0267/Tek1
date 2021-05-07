/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void init_particle(rpg_t *rpg)
{
    rpg->game->in_game->particle->xp[0] = put_in_vector2f(960, 590);
    rpg->game->in_game->particle->xp[1] = put_in_vector2f(925, 580);
    rpg->game->in_game->particle->xp[2] = put_in_vector2f(995, 580);
    rpg->game->in_game->particle->xp[3] = put_in_vector2f(960, 540);
    rpg->game->in_game->particle->xp[4] = put_in_vector2f(925, 530);
    rpg->game->in_game->particle->xp[5] = put_in_vector2f(995, 530);
}

void init_particle_blood(rpg_t *rpg, sfVector2f pos)
{
    pos.x += 27;
    pos.y += 44;
    rpg->game->in_game->particle->blood_color = sfColor_fromRGB(209, 52, 51);
    rpg->game->in_game->particle->blood[0] = put_in_vector2f(pos.x + 10, pos.y);
    rpg->game->in_game->particle->blood[1] = put_in_vector2f(pos.x + 10, pos.y);
    rpg->game->in_game->particle->blood[2] = put_in_vector2f(pos.x - 10, pos.y);
    rpg->game->in_game->particle->blood[3] = put_in_vector2f(pos.x - 10, pos.y);
}