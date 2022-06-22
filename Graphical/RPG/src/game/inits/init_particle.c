/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void init_particle(rpg_t *rpg)
{
    rpg->game->in_game->stats->xp_anim[0] = put_in_vector2f(960, 590);
    rpg->game->in_game->stats->xp_anim[1] = put_in_vector2f(925, 580);
    rpg->game->in_game->stats->xp_anim[2] = put_in_vector2f(995, 580);
    rpg->game->in_game->stats->xp_anim[3] = put_in_vector2f(960, 540);
    rpg->game->in_game->stats->xp_anim[4] = put_in_vector2f(925, 530);
    rpg->game->in_game->stats->xp_anim[5] = put_in_vector2f(995, 530);
}

void init_particle_blood(sfVector2f pos, particle_t *particle_list)
{
    pos.x += 27;
    pos.y += 44;
    particle_list->blood_color = sfColor_fromRGB(209, 52, 51);
    particle_list->blood[0] = put_in_vector2f(pos.x + 10, pos.y);
    particle_list->blood[1] = put_in_vector2f(pos.x + 10, pos.y);
    particle_list->blood[2] = put_in_vector2f(pos.x - 10, pos.y);
    particle_list->blood[3] = put_in_vector2f(pos.x - 10, pos.y);
}