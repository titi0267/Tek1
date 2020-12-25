/*
** EPITECH PROJECT, 2020
** My_structure by Timothy CONIEL
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_
#include <SFML/Graphics.h>

typedef struct map_s
{
    int buffer_size;
    char *buffer;
    char **line;
} map_t;

typedef struct background_s
{
    sfVector2f position_back;
    sfVector2f pos_back;
    sfVector2f position_bott;
    sfVector2f pos_bottom;
} background_t;

typedef struct player_s
{
    sfTexture *bird_tex;
    sfSprite *my_bird;
    sfVector2f position;
    sfIntRect anim;
    int offset;
    sfVector2i collision_up;
    sfVector2i collision_down;
    int is_collision;
} player_t;

typedef struct enemy_s
{
    sfTexture *pipe_tex;
    sfSprite *my_pipe;
    sfSprite *my_pipe2;
    sfVector2f enemy_pos;
    sfVector2f enemy_pos2;
    sfVector2f enemy_pos3;
    sfVector2f enemy_pos4;
    sfVector2f enemy_pos5;
    sfVector2f enemy_pos6;
    sfVector2f enemy_pos7;
    sfVector2f enemy_pos8;
} enemy_t;
#endif /* !MY_STRUCT_H_ */
