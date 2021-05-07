/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** particle
*/

// 60; 108;
// {930, 486}

#include "../../../include/func_name.h"

void creat_rect(rpg_t *rpg, sfVector2f vect, float diff)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = {vect.x, vect.y},
    .color = sfYellow};
    sfVertex vertex2 = {.position = {vect.x + 5, vect.y},
    .color = sfYellow};
    sfVertex vertex3 = {.position = {vect.x, vect.y + 15 - diff},
    .color = sfRed};
    sfVertex vertex4 = {.position = {vect.x + 5, vect.y + 15 - diff},
    .color = sfRed};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(rpg->basic->wnd->my_wnd, vertex_array, NULL);
}

void creat_square(rpg_t *rpg, sfVector2f vect)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = {vect.x, vect.y},
    .color = rpg->game->in_game->particle->blood_color};
    sfVertex vertex2 = {.position = {vect.x + 10, vect.y},
    .color = rpg->game->in_game->particle->blood_color};
    sfVertex vertex3 = {.position = {vect.x, vect.y + 10},
    .color = rpg->game->in_game->particle->blood_color};
    sfVertex vertex4 = {.position = {vect.x + 10, vect.y + 10},
    .color = rpg->game->in_game->particle->blood_color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(rpg->basic->wnd->my_wnd, vertex_array, NULL);
}

void move_xp(rpg_t *rpg)
{
    for (int i = 0; i <= 5; i++)
        rpg->game->in_game->particle->xp[i].y -= 2;
}

void creat_level_up(rpg_t *rpg)
{
    static float diff = 0;
    static float time = 0;

    if (rpg->game->in_game->stats->level_up == 1) {
        time += rpg->basic->cnf->clk->time_loop;
        for (int i = 0; i <= 5; i++)
            creat_rect(rpg, rpg->game->in_game->particle->xp[i], diff);
        if (time >= 0.02) {
            move_xp(rpg);
            time = 0;
            diff += 1;
        }
        if (rpg->game->in_game->particle->xp[4].y <= 496) {
            rpg->game->in_game->stats->level_up = 0;
            diff = 0;
            time = 0;
            init_particle(rpg);
        }
    }
}

void move_blood(rpg_t *rpg)
{
    rpg->game->in_game->particle->blood[0].x -= 3;
    rpg->game->in_game->particle->blood[0].y += 5;
    rpg->game->in_game->particle->blood[1].y += 5;
    rpg->game->in_game->particle->blood[2].y += 5;
    rpg->game->in_game->particle->blood[3].x += 3;
    rpg->game->in_game->particle->blood[3].y += 5;
    rpg->game->in_game->particle->blood_color.r = (rpg->game->in_game->
    particle->blood_color.r - 7 < 0) ? 0 : rpg->game->in_game->
    particle->blood_color.r - 7;
    rpg->game->in_game->particle->blood_color.g = (rpg->game->in_game->
    particle->blood_color.g - 7 < 0) ? 0 : rpg->game->in_game->
    particle->blood_color.g - 7;
    rpg->game->in_game->particle->blood_color.b = (rpg->game->in_game->
    particle->blood_color.b - 7 < 0) ? 0 : rpg->game->in_game->
    particle->blood_color.b - 7;
}

void creat_blood(rpg_t *rpg, enemy_t *nmi_list)
{
    static float time = 0;
    static int nbr = 0;

    if (nmi_list->blooding == 1) {
        if (time == 0)
            init_particle_blood(rpg, nmi_list->nmi_pos);
        time += rpg->basic->cnf->clk->time_loop;
        for (int i = 0; i <= 3; i++)
            creat_square(rpg, rpg->game->in_game->particle->blood[i]);
        if (time >= 0.005) {
            time = 0.001;
            move_blood(rpg);
            nbr++;
        }
        if (nbr == 20) {
            time = 0;
            nbr = 0;
            nmi_list->blooding = 0;
        }
    }
}