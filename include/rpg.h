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

typedef struct basics_s basics_t;
struct basics_s {
    sfRenderWindow *my_window;
    sfClock *clock;
    sfEvent event;
    float time_total;
    float time_loop;
    int win_width;
    int win_height;
    int fps;
    sfVector2i mouse;
};

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
};

typedef struct rpg_s rpg_t;
struct rpg_s {
    basics_t *basics;
    main_menu_t *main_menu;
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

#endif /* !RPG_H_ */