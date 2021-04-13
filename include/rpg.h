/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "basics.h"
#include "func_name.h"

#define MALLOC_ERROR 84

typedef struct control_s {
    char *up;
    char *down;
    char *right;
    char *left;
    char *run;
    char *inventory;
    char *cellphone;
    char *car;
    char *quadcopter;
} control_t;

typedef struct main_menu_s main_menu_t;
struct main_menu_s {
    sfSprite *background;
    sfTexture *create_background;
    sfIntRect rect_but;
    sfIntRect rect_logo;
    sfIntRect rect_pegi;
    int line_rect;
    int line_logo;
    int offset;
    int offset_logo;
    int offset_pegi;
    int line_pegi;
    sfSprite *main_menu;
    sfTexture *create_main_menu;
    sfSprite **menu;
    sfSprite *pegi_spt;
    sfSprite *basil_spt;
    int wait_basil;
    int wait_pegi;
    sfSoundBuffer *create_start;
    sfSound *start;
    sfSoundBuffer *create_a_menu;
    sfSound *a_menu;
    sfSprite **options;
    int opt_status;
    sfSprite **sound;
    sfSprite **graphismes;
    sfTexture *empty_square;
    sfTexture *fill_square;
};

typedef struct rpg_s rpg_t;
struct rpg_s {
    basic_t *basic;
    main_menu_t *main_menu;
    control_t *control;
    int status;
};

typedef enum menu_s {
    NEW_GAME,
    CONTINUE,
    TUTORIAL,
    OPTIONS,
    QUIT,
    NONE
} menu_t;

typedef enum options_s {
    GRAPH_F,
    SOUND_F,
    GAME_OPTIONS_F,
    GRAPH,
    SOUND,
    GAME_OPTIONS,
    MAIN_MENU,
    NO
} options_t;

typedef enum graph_sound_s {
    CIRCLE_MUSIC,
    CIRCLE_DIAG,
    CIRCLE_AMBT,
    RES19x80,
    RES12x20,
    RES11x30,
    FPS30,
    FPS60
} graph_sound_t;

int create_window(rpg_t *rpg);
float adapt_x(rpg_t *rpg, int hitbox_x);
float adapt_y(rpg_t *rpg, int hitbox_y);
void init_menu_quit(rpg_t *rpg);
int parsing(rpg_t *rpg);
int background(rpg_t *rpg);
int main_menu(rpg_t *rpg);

void background_pegi(rpg_t *rpg);
void move_basil(rpg_t *rpg);
void init_logo_spt(rpg_t *rpg);
void init_pegi_spt(rpg_t *rpg);

void init_rect_adn(rpg_t *rpg);
int init_main_menu(rpg_t *rpg);
void create_boom(rpg_t *rpg);
void hitbox1(rpg_t *rpg);
void hitbox2(rpg_t *rpg);
void clic1(rpg_t *rpg);
void parsing_menu2(rpg_t *rpg);

void options(rpg_t *rpg);
void init_option1(rpg_t *rpg);
void init_controls(rpg_t *rpg);
void init_bt_opt(rpg_t *rpg);
void sound_cirle(rpg_t *rpg);
void create_size_square(rpg_t *rpg);
void select_fps(rpg_t *rpg);
void select_resolution(rpg_t *rpg);
int manage_window_size(rpg_t *rpg);
void show_menus2(rpg_t *rpg);
void clic_menu(rpg_t *rpg);
void draw_square(rpg_t *rpg);
void manage_fill_resolution(rpg_t *rpg);
void show_music_sound(rpg_t *rpg);
void manage_sound(rpg_t *rpg);

#endif /* !RPG_H_ */