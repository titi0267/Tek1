/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** particle
*/

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

void creat_square(rpg_t *rpg, sfVector2f vect, particle_t *particle_list)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = {vect.x, vect.y},
    .color = particle_list->blood_color};
    sfVertex vertex2 = {.position = {vect.x + 10, vect.y},
    .color = particle_list->blood_color};
    sfVertex vertex3 = {.position = {vect.x, vect.y + 10},
    .color = particle_list->blood_color};
    sfVertex vertex4 = {.position = {vect.x + 10, vect.y + 10},
    .color = particle_list->blood_color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(rpg->basic->wnd->my_wnd, vertex_array, NULL);
}

void creat_level_up(rpg_t *rpg)
{
    static float diff = 0;
    static float time = 0;

    if (rpg->game->in_game->stats->level_up == 1) {
        time += rpg->basic->cnf->clk->time_loop;
        for (int i = 0; i <= 5; i++)
            creat_rect(rpg, rpg->game->in_game->stats->xp_anim[i], diff);
        if (time >= 0.02) {
            move_xp(rpg);
            time = 0;
            diff += 1;
        }
        if (rpg->game->in_game->stats->xp_anim[4].y <= 496) {
            rpg->game->in_game->stats->level_up = 0;
            diff = 0;
            time = 0;
            init_particle(rpg);
        }
    }
}

int add_particle_list(rpg_t *rpg, enemy_t *nmi_list)
{
    rpg->game->in_game->particle_list = (*rpg->game->in_game->particle);
    if ((rpg->game->in_game->particle_list = malloc
    (sizeof(*(rpg->game->in_game->particle_list)))) == NULL)
        return (MALLOC_ERROR);

    if ((rpg->game->in_game->particle_list->blood =
    malloc(sizeof(sfVector2f) * 5)) == NULL)
        return (MALLOC_ERROR);
    init_particle_blood(nmi_list->nmi_pos, rpg->game->in_game->particle_list);
    rpg->game->in_game->particle_list->nbr = 0;
    rpg->game->in_game->particle_list->tm = 0;
    rpg->game->in_game->particle_list->next = *(rpg->game->in_game->particle);
    *(rpg->game->in_game->particle) = rpg->game->in_game->particle_list;
    return (0);
}

void move_blood(particle_t *particle_list)
{
    particle_list->blood[0].x -= 3;
    particle_list->blood[0].y += 5;
    particle_list->blood[1].y += 5;
    particle_list->blood[2].y += 5;
    particle_list->blood[3].x += 3;
    particle_list->blood[3].y += 5;
    particle_list->blood_color.r = (particle_list->blood_color.r - 7 < 0) ? 0 :
    particle_list->blood_color.r - 7;
    particle_list->blood_color.g = (particle_list->blood_color.g - 7 < 0) ? 0 :
    particle_list->blood_color.g - 7;
    particle_list->blood_color.b = (particle_list->blood_color.b - 7 < 0) ? 0 :
    particle_list->blood_color.b - 7;
}