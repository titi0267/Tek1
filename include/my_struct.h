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
    sfIntRect move_back;
    sfSprite *my_background;
    sfTexture *background;
    sfSprite *my_bottom;
    sfTexture *bottom;
    sfSprite *my_bottom1;
    sfTexture *bottom1;
    sfSprite *my_background1;
    sfTexture *background1;
} background_t;

typedef struct player_s
{
    sfTexture *bird_tex;
    sfSprite *my_bird;
    sfVector2f position;
    sfIntRect anim;
    sfVector2f *collision;
    int death;
    float rotation;
    int offset;
    int while_jump;
    int second_jump;
    int stop_jump;
    float fall_fast;
    int fit_space;
    int high;
    /*int jump;
    int high;
    int death;
    int rotate_down;
    int rotate_speed;
    int keep_pos;*/
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
    float limit;
} enemy_t;
#endif /* !MY_STRUCT_H_ */
