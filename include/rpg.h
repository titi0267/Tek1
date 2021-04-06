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
    float time_total;
    float time_loop;
    int win_width;
    int win_height;
    int fps;
};

typedef struct main_menu_s main_menu_t;
struct main_menu_s {
    sfSprite *background;
    sfTexture *create_background;
    sfIntRect rect_but;
    int offset;
    sfSprite *main_menu;
    sfTexture *create_main_menu;
};

typedef struct rpg_s rpg_t;
struct rpg_s {
    basics_t *basics;
    main_menu_t *main_menu;
    int status;
};

int create_window(rpg_t *rpg);
float adapt_x(rpg_t *rpg, int hitbox_x);
float adapt_y(rpg_t *rpg, int hitbox_y);
int parsing(rpg_t *rpg);
int background(rpg_t *rpg);
int init_main_menu(rpg_t *rpg);

#endif /* !RPG_H_ */
