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

typedef struct window_s
{
    sfRenderWindow *window;
    sfVideoMode scr_size;
} window_t;

typedef struct core_s
{
    window_t *wnd;
} core_t;

#endif /* !struct_header */
