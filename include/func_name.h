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
#include <math.h>
#include <unistd.h>
#include <math.h>

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
int parsing(rpg_t *rpg);
void background(rpg_t *rpg);
int main_menu(rpg_t *rpg);

void background_pegi(rpg_t *rpg);
void move_basil(rpg_t *rpg);
void init_logo_spt(rpg_t *rpg);
void init_pegi_spt(rpg_t *rpg);

void init_rect_adn(rpg_t *rpg);
void init_main_menu(rpg_t *rpg);
void hitbox1(rpg_t *rpg);
void hitbox2(rpg_t *rpg);
int clic1(rpg_t *rpg);
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
void select_characters(rpg_t *rpg);
void player_stop(rpg_t *rpg);
void hover_perso2(rpg_t *rpg);
void hover_perso1(rpg_t *rpg);
void stopped_moving(rpg_t *rpg);
sfVector2u put_in_vector2u(unsigned int x, unsigned int y);
int game_malloc(rpg_t *rpg);
int check_color(rpg_t *rpg, sfColor color);
int check_collision(rpg_t *rpg, int direction);
int set_key_color(rpg_t *rpg);
int collision(rpg_t *rpg, int direction, int y);
void init_warren_map(rpg_t *rpg);

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

int init_pdown_up_rect(rpg_t *rpg);
int create_police_map(rpg_t *rpg);
void rect_move_player(rpg_t *rpg, int direction);
void move_side_map(rpg_t *rpg, int on_map);
void print_player_move(rpg_t *rpg);
void chose_map(rpg_t *rpg);
void set_player_rect(rpg_t *rpg);
int compare_equal_colors(sfColor c1, sfColor c2);
void move_left_map(rpg_t *rpg, int on_map);
void player_stop(rpg_t *rpg);
void change_map(rpg_t *rpg);

sfVector2f put_in_vector2f(float x, float y);
void assemble_spt_pause(rpg_t *rpg);
int show_menus(rpg_t *rpg);
int show_menus2(rpg_t *rpg);
void clic_options1(rpg_t *rpg);
void clic_options(rpg_t *rpg);
void init_exit_option1(rpg_t *rpg);
void options_exit(rpg_t *rpg);
void clic_menu(rpg_t *rpg);
int init_tuto(rpg_t *rpg);
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
void free_all(rpg_t *rpg);
void destroy_all(rpg_t *rpg);
int realrandom(void);
char *my_strcat(char *begin, char *end);
char *my_putnbr(int nb);
int my_strlen(char *str);

void save_map(rpg_t *rpg);
void load_save(rpg_t *rpg);
int my_getnbr(char const *str);
void init_car_spt(rpg_t *rpg);
void print_car(rpg_t *rpg);

void detect_weapon(rpg_t *rpg);
void drag(rpg_t *rpg, int selected);
void calc_vector(rpg_t *rpg, int slot_type, int weapon);
void drag_and_drop(rpg_t *rpg, int selected);
void set_pos_car(rpg_t *rpg);
void enterred_in_car(rpg_t *rpg);
int point_distcance(sfVector2f mouse, sfVector2f map);
void player_run(rpg_t *rpg);
sfVector2f vect_diff(sfVector2f first, sfVector2f second);
sfVector2f vect_add(sfVector2f first, sfVector2f second);

#endif /* !prototype */
