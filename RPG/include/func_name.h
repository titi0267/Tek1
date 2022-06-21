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

void create_window(basic_t *basic);
void create_boom(menu_t *menu);

int open_window(rpg_t *rpg);
void inside_open(rpg_t *rpg);
void event(rpg_t *rpg);
void get_mouse_pos(basic_t *basic);
void move_clock(cloc_t *clk);
float adapt_x(rpg_t *rpg, int hitbox_x);
float adapt_y(rpg_t *rpg, int hitbox_y);
void init_menu_quit(rpg_t *rpg);
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
int check_color(rpg_t *rpg, sfColor color);
int check_collision(rpg_t *rpg, int direction);
int set_key_color(rpg_t *rpg);
int collision(rpg_t *rpg, int direction, int y);
void init_warren_map(rpg_t *rpg);

void init_inventory(rpg_t *rpg);
void drop_all_boxes(rpg_t *rpg);
void detect_inventory_object(rpg_t *rpg);
void display_inventory(rpg_t *rpg);
void drag(rpg_t *rpg, int selected);
int game_malloc(rpg_t *rpg);
int game_malloc2(rpg_t *rpg);
void init_exit(rpg_t *rpg);
void key_event_game(rpg_t *rpg);
void key_event_inventory(rpg_t *rpg);
void click_on_resume(rpg_t *rpg);
void click_on_option(rpg_t *rpg);
void click_on_quit(rpg_t *rpg);
void display_loots(rpg_t *rpg);

int init_pdown_up_rect(rpg_t *rpg);
int create_police_map(rpg_t *rpg);
void rect_move_player(rpg_t *rpg, int direction);
void rect_move_enemy(rpg_t *rpg, int direction, enemy_t *nmi_list);
void enemy_stop(rpg_t *rpg);
void detect_player(rpg_t *rpg);
void move_side_map(rpg_t *rpg, int on_map);
void print_player_move(rpg_t *rpg);
void chose_map(rpg_t *rpg);
void set_player_rect(rpg_t *rpg);
int compare_equal_colors(sfColor c1, sfColor c2);
int choose_map_outside_police(rpg_t *rpg);
int place_outside_police(rpg_t *rpg);
void move_left_map(rpg_t *rpg, int on_map, objects_t *objects, map_t *map);
void rect_move_car(rpg_t *rpg, objects_t *obj, int direction);
void player_stop(rpg_t *rpg);
int spawn_enemies(rpg_t *rpg);
void change_map(rpg_t *rpg);

sfVector2f put_in_vector2f(float x, float y);
sfVector2i put_in_vector2i(int x, int y);
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
void print_car(rpg_t *rpg, int direction);
float vol_checker(float x);
int init_function(rpg_t *rpg);
void init_basic_value(rpg_t *rpg);
int init_before_game(rpg_t *rpg);
sfVector2f vect_x_y(sfVector2f vect, int add_x, int add_y);

void drag(rpg_t *rpg, int selected);
void calc_vector(rpg_t *rpg, int slot_type, int weapon);
void drag_and_drop(rpg_t *rpg, int selected);
void set_pos_car(rpg_t *rpg);
void enter_car(rpg_t *rpg);
int point_distcance(sfVector2f mouse, sfVector2f map);
void player_run(rpg_t *rpg);
sfVector2f vect_diff(sfVector2f first, sfVector2f second);
sfVector2f vect_add(sfVector2f first, sfVector2f second);
void init_amb_tuto_game(rpg_t *rpg);
void ambiant_tuto(rpg_t *rpg);
void ambiant_game(rpg_t *rpg);
void start_actions(rpg_t *rpg);
void parsing_avance(rpg_t *rpg);
void init_phone(rpg_t *rpg);
void print_phone(rpg_t *rpg);
void toggle_phone(rpg_t *rpg);
void phone_main(rpg_t *rpg);
void init_phone_sound(rpg_t *rpg);
void desk_hitbox(rpg_t *rpg);
int init_yellow_man(rpg_t *rpg);
void init_pitch_riley(rpg_t *rpg);
int move_enemies(rpg_t *rpg);
int on_cine(rpg_t *rpg);
void notif2_hitbox(rpg_t *rpg);
void move_enemies_on_map(rpg_t *rpg, int direction);
void call_hitbox(rpg_t *rpg);
void init_pitch_riley(rpg_t *rpg);
void incall_hitbox(rpg_t *rpg);
int malloc_stat_player(rpg_t *rpg);
void init_stats_value(rpg_t *rpg);
void print_stats(rpg_t *rpg);
void init_xplife(rpg_t *rpg);
void print_life(rpg_t *rpg);
int enemy_collision(rpg_t *rpg, int direction, enemy_t *nmi_list, int sub);
void print_xp_life(rpg_t *rpg);
void creat_level_up(rpg_t *rpg);
int check_enemy_collision(rpg_t *rpg, int direction, enemy_t *nmi_list,
int sub);
void init_particle(rpg_t *rpg);
void init_particle_blood(sfVector2f pos, particle_t *particle_list);
void creat_blood(rpg_t *rpg, enemy_t *nmi_list);
void button_hitbox(rpg_t *rpg);
void enemy_rect_move_to_player(rpg_t *rpg, enemy_t *nmi_list);
void define_direction(rpg_t *rpg, enemy_t *nmi_list);
int move_enemy_right(rpg_t *rpg, enemy_t *nmi_list, int sub, int yes);
int move_enemy_left(rpg_t *rpg, enemy_t *nmi_list, int sub, int yes);
int move_enemy_down(rpg_t *rpg, enemy_t *nmi_list, int sub, int yes);
int move_enemy_up(rpg_t *rpg, enemy_t *nmi_list, int sub, int yes);
char *save_stats(rpg_t *rpg);
char *save_avance(rpg_t *rpg);
void reload_new_game(rpg_t *rpg);
void init_policemen(rpg_t *rpg);
void init_warren(rpg_t *rpg);
void init_alerts(rpg_t *rpg);
void car_hitbox(rpg_t *rpg);
void warren_hitbox(rpg_t *rpg);
void parsing_story(rpg_t *rpg);
void cdc_hitbox(rpg_t *rpg);
void init_covid(rpg_t *rpg);
void shoot_bullet(rpg_t *rpg);
int init_bullet(rpg_t *rpg);
void draw_bullet(rpg_t *rpg);
void move_bullet_up(rpg_t *rpg, bullets_t *bullet_list);
void move_bullet_left(rpg_t *rpg, bullets_t *bullet_list);
void move_bullet_right(rpg_t *rpg, bullets_t *bullet_list);
void move_bullet_down(rpg_t *rpg, bullets_t *bullet_list);
void init_knife(rpg_t *rpg);
void draw_knife(rpg_t *rpg);
int main_parsing(rpg_t *rpg);
int parsing_1(rpg_t *rpg);
void parsing_2(rpg_t *rpg);
void parsing_3(rpg_t *rpg);
int parsing_4(rpg_t *rpg);
void init_road_spt(rpg_t *rpg);
void init_cinematic2_audio(rpg_t *rpg);
void cinematic_2(rpg_t *rpg);
void parsing_5(rpg_t *rpg);
void collision_enemy_bullet(rpg_t *rpg);
void init_credits(rpg_t *rpg);
void pop_bullet(rpg_t *rpg, bullets_t *bullet_list);
void credits(rpg_t *rpg);
void attack_cut(rpg_t *rpg, enemy_t *nmi_list);
int add_particle_list(rpg_t *rpg, enemy_t *nmi_list);
void creat_square(rpg_t *rpg, sfVector2f vect, particle_t *particle_list);
void move_blood(particle_t *particle_list);
void init_levelup_stat(rpg_t *rpg);
void print_level_up(rpg_t *rpg);
void vaccine_manager(rpg_t *rpg);
void elevator_hitbox(rpg_t *rpg);
void init_stats_basic_value(rpg_t *rpg);
int choose_map_cdc_in(rpg_t *rpg);
void print_map_loot(rpg_t *rpg);
void init_bullet_proof(rpg_t *rpg);
void init_bullets(rpg_t *rpg);
int game_malloc3(rpg_t *rpg);
void init_stuff(rpg_t *rpg);
void weapon_hitbox(rpg_t *rpg);
void bullet_hitbox(rpg_t *rpg);
void vest_hitbox(rpg_t *rpg);
void begin_nmi_spawn(rpg_t *rpg);
void display_vest_in_inv(rpg_t *rpg);
char *save_invent(rpg_t *rpg);
void weapon_hitbox2(rpg_t *rpg);
void init_lose_text(rpg_t *rpg);
void lose_game(rpg_t *rpg);
int create_player_vest(rpg_t *rpg);
void destroy_enemies(rpg_t *rpg);
void load_value2(char *map, rpg_t *rpg);
void stop_car(rpg_t *rpg, int possible);
void bullet_direction(rpg_t *rpg, bullets_t *bullet_list);
void init_rect_car(objects_t *obj);
void move_xp(rpg_t *rpg);
void reset_inventory(rpg_t *rpg);
void init_positions(rpg_t *rpg);
void print_warren(rpg_t *rpg);

#endif /* !prototype */