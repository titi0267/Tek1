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
    .color = sfYellow};
    sfVertex vertex4 = {.position = {vect.x + 5, vect.y + 15},
    .color = sfYellow};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(rpg->basic->wnd->my_wnd, vertex_array, NULL);
    //return (vertex_array);
}

void creat_level_up(rpg_t *rpg)
{
    static float time = 0;
    sfVector2f vect1 = put_in_vector2f(960, 540);
    sfVector2f vect2 = put_in_vector2f(925, 530);
    sfVector2f vect3 = put_in_vector2f(995, 530);

    creat_tile(rpg, vect1);
    creat_tile(rpg, vect2);
    creat_tile(rpg, vect3);
}