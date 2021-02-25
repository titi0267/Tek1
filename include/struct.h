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
} button_t;

typedef struct menu_s
{
    sfTexture *bgd_tex;
    sfSprite *bgd_spt;
    sfTexture *name_tex;
    sfSprite *name_spt;
    button_t *button;

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
