/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** particle
*/

// 60; 108;
// {930, 486}

#include "../../../include/func_name.h"

void creat_tile(rpg_t *rpg, sfVector2f vect)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = vect,
    .color = sfYellow};
    sfVertex vertex2 = {.position = {vect.x + 5, vect.y},
    .color = sfYellow};
    sfVertex vertex3 = {.position = {vect.x, vect.y + 15},
    .color = sfRed};
    sfVertex vertex4 = {.position = {vect.x + 5, vect.y + 15},
    .color = sfRed};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(rpg->basic->wnd->my_wnd, vertex_array, NULL);
}

void print_levelup(rpg_t *rpg)
{
    for (int i = 0; i <= 5; i++) {
        creat_tile(rpg, rpg->game->in_game->particle->xp[i]);
        rpg->game->in_game->particle->xp[i].y -= 2;
    }
}

void creat_level_up(rpg_t *rpg)
{
    static float time = 0;

    if (rpg->game->in_game->stats->level_up == 0) {
        time += rpg->basic->cnf->clk->time_loop;
        if (time >= 0.5)
            print_levelup(rpg);
        if (rpg->game->in_game->particle->xp[4].y <= 476) {
            rpg->game->in_game->stats->level_up = 0;
            init_particle(rpg);
        }
    }
}

// void creat_blood(rpg_t *rpg, sfVector2f pos)
// {
//     static float time = 0;

//     if (rpg->game->in_game->stats->level_up == 0) {
//         time += rpg->basic->cnf->clk->time_loop;
//         if (time >= 0.5)
//             print_levelup(rpg);
//         if (rpg->game->in_game->particle->xp[2].y <= 400) {
//             rpg->game->in_game->stats->level_up = 0;
//             init_particle(rpg);
//         }
//     }
// }