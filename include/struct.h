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

typedef struct window_s
{
    sfRenderWindow *window;
    sfVideoMode scr_size;
    sfVector2f pos;

} window_t;

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
    sfTexture *click_settings_text;
    sfSprite *click_setting_spt;
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
    int offset;
    int width_backup;
    int size_one;
} volume_t;

typedef struct settings_s
{
    sfTexture *return_tex;
    sfSprite *return_spt;
    sfTexture *hover_return_tex;
    sfSprite *hover_return_spt;
    sfTexture *fullscr_tex;
    sfSprite *fullscr_spt;
    sfTexture *hover_fullscr_tex;
    sfSprite *hover_fullscr_spt;
    sfTexture *medscr_tex;
    sfSprite *medscr_spt;
    sfTexture *hover_medscr_tex;
    sfSprite *hover_medscr_spt;
    volume_t *vol;
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
    settings_t *stg;
    sfSprite *mv_spt;
    struct menu_s *next;
    int end_gm;
    int return_to_menu;
    int settings;
    sfSprite **list;
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
} core_t;

#endif /* !struct_header */
