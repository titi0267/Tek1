/*
** EPITECH PROJECT, 2021
** menu.h
** File description:
** menu rpg
*/

#ifndef menu_scr
#define menu_scr

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct intro_sound_s {
    sfSoundBuffer *create_start;
    sfSound *start;
} intro_sound_t;

typedef struct intro_pegi_s {
    sfIntRect rect_pegi;
    int offset_pegi;
    int line_pegi;
    sfSprite *pegi_spt;
    int wait_pegi;
} intro_pegi_t;

typedef struct intro_basil_s {
    int line_logo;
    int offset_logo;
    sfIntRect rect_logo;
    sfSprite *basil_spt;
    int wait_basil;
} intro_basil_t;

typedef struct intro_s {
    intro_sound_t *intro_snd;
    intro_basil_t *intro_basil;
    intro_pegi_t *intro_pegi;
    int status;
    int window_access;
} intro_t;

typedef struct menu_snd_s {
    sfSoundBuffer *create_a_menu;
    sfSound *a_menu;
    int status_sound_menu;
} menu_snd_t;

typedef struct menu_spt_s {
    sfSprite *main_menu;
    sfTexture *create_main_menu;
    sfSprite **menu;
} menu_spt_t;

typedef struct new_game_s {
    sfSprite *background;
    sfTexture *background_txt;
    sfSprite **select;
    sfTexture **select_txt;
    sfSprite **characters;
    sfTexture **characters_txt;
    sfVector2f *pos_characters;
    sfIntRect *rect_characters;
    int *offset_character;
    int character_chosen;
    sfIntRect *char_in_game;
} new_game_t;

typedef struct main_menu_s {
    menu_snd_t *menu_snd;
    menu_spt_t *menu_spt;
    new_game_t *new_game;
} main_menu_t;

typedef struct background_adn_s {
    sfSprite *background;
    sfIntRect rect_background;
    int line_rect;
    int offset;
} background_adn_t;

#endif /* !menu_scr */
