/*
** EPITECH PROJECT, 2020
** My_structure by Timothy CONIEL
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct map_s
{
    int buffer_size;
    char *buffer;
    char **line;
    int lin_val;
    int char_val;
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
    sfSprite *winner;
    sfTexture *winner_tex;
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
    int stop;
    int fall_dead;
    float rotate_speed;
    int angle_down;
    int move_pipe;
    int col_arr;
    int aft_pip;
    float angle;
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
    int pos_x;
    int pos_di;
    int pos_uf;
    int fill_d;
    int death_i;
    float limit;
    int restart_game;
} enemy_t;

typedef struct time_s
{
    sfClock *clock;
    float elapsed_time;
    float delta_time;
}time_t;

typedef struct window_s
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
} window_t;

typedef struct score_s
{
    sfText *text;
    sfText *high_score;
    sfText *your_score;
    sfText *text_score;
    sfText *text_increase;
    sfFont *font;
    sfFont *font1;
    sfVector2f position_increase;
    sfVector2f pos_best;
    int amount;
    int max;
    int actual;
    int increase_score;
    char *score_disp;
    char *current;
    char *max_disp;
    int win;
} score_t;

typedef struct sound_s
{
    sfSoundBuffer *coin_buf;
    sfSound *coin;
    sfSoundBuffer *death_buf;
    sfSound *death;
    sfSoundBuffer *jump_buf;
    sfSound *jump;
    sfSound *out_gm;
    sfSoundBuffer *out_gm_buf;
    sfSound *death_down;
    sfSoundBuffer *death_down_bu;
    int played;
} sound_t;

typedef struct menu_s
{
    sfSprite *button;
    sfSprite *black_but;
    sfSprite *load;
    sfSprite *gm_ovr;
    sfTexture *game_ovr;
    sfTexture *loading;
    sfTexture *black_tex;
    sfTexture *button_tex;
    sfVector2f position;
    sfText *press;
    sfText *count;
    sfFont *font;
    int font_size;
    sfVector2f text_pos;
    sfVector2f count_pos;
    sfVector2f pos_death;
    sfVector2f scale;
    sfVector2f black_scale;
    sfVector2f pos_black;
    int change_button;
    int countdown;
    char *counter;
    int game_starting;
    int random_move1;
    int random_move2;
    int random;
    int delay;
    int start_count;
    int stop_game;
    int restart;
    int button_black;
} menu_t;

typedef struct gather_s
{
    background_t back;
    player_t bird;
    enemy_t enemy;
    score_t score;
    sound_t sound;
    time_t time;
    window_t windo;
    menu_t menu;
} gather_t;

#endif /* !MY_STRUCT_H_ */
