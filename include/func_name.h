/*
** EPITECH PROJECT, 2021
** include prototype
** File description:
** prototype.h
*/

#ifndef prototype
#define prototype

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "assemble.h"

int first_alloc(rpg_t *rpg);
int basic_malloc(basic_t *basic);
int menu_alloc(menu_t *menu);
int menu_alloc_next(menu_t *menu);
int alloc_all(rpg_t *rpg);

int init_basic_value(rpg_t *rpg);

void create_window(basic_t *basic);
void create_boom(menu_t *menu);

void open_window(rpg_t *rpg);
void inside_open(rpg_t *rpg);
void event(rpg_t *rpg);
void get_mouse_pos(basic_t *basic);
void move_clock(cloc_t *clk);
float adapt_x(rpg_t *rpg, int hitbox_x);
float adapt_y(rpg_t *rpg, int hitbox_y);
void init_menu_quit(rpg_t *rpg);
void parsing(rpg_t *rpg);
void background(rpg_t *rpg);
void main_menu(rpg_t *rpg);

void background_pegi(rpg_t *rpg);
void move_basil(rpg_t *rpg);
void init_logo_spt(rpg_t *rpg);
void init_pegi_spt(rpg_t *rpg);

void init_rect_adn(rpg_t *rpg);
void init_main_menu(rpg_t *rpg);
void hitbox1(rpg_t *rpg);
void hitbox2(rpg_t *rpg);
void clic1(rpg_t *rpg);
void parsing_menu2(rpg_t *rpg);

void options(rpg_t *rpg);
void init_pause(rpg_t *rpg);
void init_option1(rpg_t *rpg);
void init_controls(rpg_t *rpg);
void init_bt_opt(rpg_t *rpg);
void sound_cirle(rpg_t *rpg);
void create_size_square(rpg_t *rpg);
void select_fps(rpg_t *rpg);
void select_resolution(rpg_t *rpg);
void manage_window_size(rpg_t *rpg);
void clic_menu(rpg_t *rpg);
void draw_square(rpg_t *rpg);
void manage_fill_resolution(rpg_t *rpg);
void manage_sound(rpg_t *rpg);
void init_new_game(rpg_t *rpg);
void choose_perso(rpg_t *rpg);
void sound(rpg_t *rpg, int status);
void move_characters(rpg_t *rpg, int character);
void init_characters_sprites(rpg_t *rpg);
void display_character_at_stop(rpg_t *rpg, int charac);
int game_malloc(rpg_t *rpg);

void init_inventory(rpg_t *rpg);
void display_inventory(rpg_t *rpg);
int game_malloc(rpg_t *rpg);
int game_malloc2(rpg_t *rpg);
void init_exit(rpg_t *rpg);
void key_event_game(rpg_t *rpg);
void key_event_inventory(rpg_t *rpg);
void click_on_resume(rpg_t *rpg);
void click_on_option(rpg_t *rpg);
void click_on_quit(rpg_t *rpg);

sfVector2f put_in_vector2f(float x, float y);
void assemble_spt_pause(rpg_t *rpg);
int show_menus(rpg_t *rpg);
int show_menus2(rpg_t *rpg);
void clic_options1(rpg_t *rpg);
void clic_options(rpg_t *rpg);
void init_exit_option1(rpg_t *rpg);
void options_exit(rpg_t *rpg);
void clic_menu(rpg_t *rpg);
void init_tuto(rpg_t *rpg);
void tuto1(rpg_t *rpg);

void init_text(rpg_t *rpg);
int malloc_text(menu_t *menu);
void manage_key(rpg_t *rpg);
void change_control(rpg_t *rpg);
void reload_control(setting_t *stg);
void tuto_map(rpg_t *rpg);
void init_map_tuto(rpg_t *rpg);
void init_cinematic1_audio(rpg_t *rpg);
void init_radio_spt(rpg_t *rpg);
void cinematic_1(rpg_t *rpg);

#endif /* !prototype */
