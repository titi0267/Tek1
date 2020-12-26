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
} player_t;

typedef struct enemy_s
{
    sfTexture *pipe_tex;
    sfTexture *pipe_tex_u;
    sfTexture *pipe_tex_d;
    sfSprite *my_pipe;
    sfSprite *my_pipe_d;
    sfSprite *my_pipe_u;
    sfVector2f enemy_pos;
    sfVector2f *pos;
    sfVector2f *pos_u;
    sfVector2f *pos_d;
    int wich_p;
} enemy_t;
#endif /* !MY_STRUCT_H_ */
