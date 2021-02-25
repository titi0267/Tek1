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
    sfSprite *sandwich1;
    sfVector2f pos;

} window_t;

typedef struct menu_s
{
    sfTexture *bgd_tex;
    sfSprite *bgd_spt;
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
