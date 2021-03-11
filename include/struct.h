/*
** EPITECH PROJECT, 2021
** struct by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** struct.h
*/

#ifndef struct_header
#define struct_header
#include "defender.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#define ERROR 84
#define TRUE 1
#define FALSE 0

typedef struct wave_s
{
    int nb_wave;
    int pirate_one;
    int pirate_two;
    int pirate_three;
    int boss;
} wave_t;

typedef struct shop_s
{
    sfVector2f pos;
    int price;
    struct shop_s *next;
} shop_t;

typedef struct eco_center_s
{
    sfVector2f pos;
    int earn;
    int rate;
    struct eco_center_s *next;
} eco_center_t;

typedef struct defense_s
{
    sfVector2f pos;
    int damage;
    int range;
    struct defense_s *next;
} defense_t;

typedef struct pirat_spt_s
{
    sfTexture *pirat_txt;
    sfSprite *pirat_spt_walk;
    sfSprite *pirat_spt_death;
} pirat_spt_t;

typedef struct pirat_data_s
{
    int life;
    int speed;
    int road;
    int x;
    int y;
    sfVector2f pos;
    struct pirat_data_s *next;
} pirat_data_t;

typedef struct enemy_s
{
    pirat_spt_t *pirat;
    pirat_data_t *data;
} enemy_t;

typedef struct game_s
{
    sfTexture *game_bgd_tex;
    sfSprite *game_bgd_spt;
} game_t;

typedef struct window_s
{
    sfRenderWindow *window;
    sfVideoMode scr_size;
    sfVector2f pos;
} window_t;

typedef enum scenes_s {scene_menu = 1, scene_settings = 2, scene_game = 3, no_scene = 4} scenes_t;

typedef struct button_s
{
    sfTexture *play_tex;
    sfSprite *play_spt;
    sfTexture *click_play_tex;
    sfSprite *click_play_spt;
    sfTexture *setting_tex;
    sfSprite *setting_spt;
    sfTexture *leave_tex;
    sfSprite *leave_spt;
    sfTexture *hover_setting_tex;
    sfSprite *hover_setting_spt;
    sfTexture *hover_play_tex;
    sfSprite *hover_play_spt;
    sfTexture *hover_leave_tex;
    sfSprite *hover_leave_spt;
    sfSprite *click_leave_spt;
    sfTexture *click_leave_tex;
    sfTexture *click_settings_tex;
    sfSprite *click_setting_spt;
    int click_on_play;
    int enable_click;
    int end_gm;
} button_t;

typedef struct volume_s
{
    sfTexture *vol_tex;
    sfSprite *vol_spt;
    sfSprite *vol_nbr_spt;
    sfTexture *vol_nbr_tex;
    sfIntRect vol_nbr;
    sfTexture *up_tex;
    sfSprite *up_spt;
    sfTexture *down_tex;
    sfSprite *down_spt;
    sfTexture *up_click_tex;
    sfSprite *up_click_spt;
    sfTexture *down_click_tex;
    sfSprite *down_click_spt;
    sfTexture *hover_down_tex;
    sfSprite *hover_down_spt;
    sfTexture *hover_up_tex;
    sfSprite *hover_up_spt;
    int offset;
    int width_backup;
    int size_one;
    int click_down;
    int click_up;
} volume_t;

typedef struct settings_s
{
    sfTexture *return_tex;
    sfSprite *return_spt;
    sfTexture *hover_return_tex;
    sfSprite *hover_return_spt;
    sfTexture *click_return_tex;
    sfSprite *click_return_spt;
    sfTexture *fullscr_tex;
    sfSprite *fullscr_spt;
    sfTexture *hover_fullscr_tex;
    sfSprite *hover_fullscr_spt;
    sfTexture *click_fullscr_tex;
    sfSprite *click_fullscr_spt;
    sfTexture *medscr_tex;
    sfSprite *medscr_spt;
    sfTexture *hover_medscr_tex;
    sfSprite *hover_medscr_spt;
    sfTexture *click_medscr_tex;
    sfSprite *click_medscr_spt;
    volume_t *vol;
    int click_medscr;
    int click_fullscr;
} settings_t;

typedef struct menu_s
{
    sfTexture *bgd_tex;
    sfSprite *bgd_spt;
    sfTexture *name_tex;
    sfSprite *name_spt;
    sfTexture *set_bg_tex;
    sfSprite *set_bg_spt;
    button_t *button;
    scenes_t scene_one;
    scenes_t scene_two;
    settings_t *stg;
    sfSprite *mv_spt;
    int return_to_menu;
    int settings;
    int click_on_stg;
    int go_to_stg;
    int menu_bg;
    int game_bgd;
} menu_t;

typedef struct time_s
{
    sfClock *clock;
    float elapsed_time;
    float delta_time;
}time_t;

typedef struct core_s
{
    window_t *wnd;
    time_t *time;
    menu_t *menu;
    game_t *game;
    enemy_t *enemy;
    wave_t *wave;
} core_t;

#endif /* !struct_header */
