/*
** EPITECH PROJECT, 2021
** game.h
** File description:
** rpg game
*/

#ifndef gm
#define gm
#define COLLISION 1
#define BEHIND 2
#define BTW_MAP 3

typedef struct start_s
{
    sfSprite *radio;
    sfIntRect radio_rect;
    int radio_offset;
    int radio_line;
    int wait_radio;
    sfSoundBuffer *cine1;
    sfSound *cinematic_1;
    int status_cinematic1;
} start_t;

typedef struct inventory_s {
    sfSprite *inventory;
    sfTexture *inventory_txt;
    sfSprite **weapon;
    sfSprite **bullet;
    sfSprite *vaccine;
    sfTexture **weapon_txt;
    sfVector2f *pos_weapon;
    sfSprite *add_damage;
    sfText *level_up_text;
    sfSprite *add_armor;
    int shortcut_it;
    int is_item_selected;
    int *is_area_filled;
    int *area_contains;
    int on_click;
    int valid;
    int selected_item;
    int vaccine_status;
    sfVector2f *pos_storage;
    sfFloatRect *glob_pos;
    int click_weapon;
    int release_weapon;
    sfVector2i **box_pos;
    int on_drag;
} inventory_t;

typedef struct stuff_s
{
    int *stuff_status;
} stuff_t;

typedef struct ig_sound_s
{
    sfSoundBuffer *amb_game;
    sfSound *game;
    int status_sound_game;
    sfSoundBuffer *riley_buffer;
    sfSound *riley;
    sfSound *riley_call;
    sfSound *riley_warren;
} ig_sound_t;

typedef struct car_s
{
    sfSprite *car;
    sfIntRect *rect_car;
    sfVector2f car_pos_tuto;
    sfVector2f car_pos;
    int car_line;
    int status;
    sfSoundBuffer *car_buffer;
    int last_dir;
    int top_car;
    sfSound *sirene;
} car_t;

typedef struct bullets_s
{
    struct bullets_s *next;
    sfSprite *bullet;
    int bullet_nbr;
    sfVector2f bullet_pos;
    int bullet_dir;
    int finish_line;
    int nbr;
} bullets_t;

typedef struct objects_s
{
    sfSprite **players;
    sfTexture **player_tex;
    sfTexture **player_vest_tex;
    sfSprite **player_vest;
    car_t *car;
    int speed_status;
    sfSprite *policemen;
    sfSprite *warren;
    sfIntRect rect_warren;
    sfSprite *knife;
    int spawn_status;
    int color_a;
} objects_t;

typedef struct map_s
{
    sfSprite **maps;
    sfImage **collisions;
    sfVector2f *pos_map;
    sfVector2u *tex_size_map;
    int *speed;
    sfVector2u *col_real;
    int last_pos;
    sfColor *color;
    int color_stat;
    int draw_car;
    int status;
    int dir;
    int car_map;
} map_t;

typedef struct enemy_s
{
    sfSprite *yellow_man;
    sfIntRect *nmi_rect;
    int last_pos;
    int *offset_nmi;
    struct enemy_s *next;
    sfVector2f nmi_pos;
    float clock_rect;
    sfVector2f diff;
    int choose_dir;
    int life;
    int blood;
    int blooding;
    int nbr;
} enemy_t;

typedef struct ig_menus_s
{
    sfSprite *exit;
    sfSprite **pause_menu;
} ig_menus_t;

typedef struct phone_s
{
    sfSprite *phone_icone;
    sfSprite *phone_notif;
    sfSprite **phone;
    sfSound *notif_sound;
    sfSoundBuffer *phone_buffer;
    sfSound *call_sound;
    sfSound *alarm;
    int phone_status;
    int notif_index;
    int notif_bool;
    int notif_prev;
    int call_status;
    int alarm_status;
} phone_t;

typedef struct player_stats_s
{
    sfText *txt;
    int value;
    int base_value;
    int total_value;
} player_stats_t;

typedef struct stat_s
{
    player_stats_t **player_stats;
    int xp_value;
    int level_up;
    int level;
    int xp_max_value;
    int losing;
    sfText *lose_txt;
    sfRectangleShape *life;
    sfRectangleShape *life_border;
    sfRectangleShape *xp;
    sfRectangleShape *xp_border;
    sfVector2f life_size;
    sfVector2f xp_size;
    sfVector2f *xp_anim;
} stat_t;

typedef struct particle_s
{
    sfVector2f *blood;
    sfColor blood_color;
    struct particle_s *next;
    float tm;
    int nbr;
} particle_t;

typedef struct in_game_s
{
    ig_sound_t *ig_sound;
    objects_t *objects;
    inventory_t *inventory;
    map_t *map;
    enemy_t **nmi;
    enemy_t *nmi_list;
    ig_menus_t *ig_menus;
    phone_t *phone;
    stat_t *stats;
    particle_t *particle_list;
    particle_t **particle;
    bullets_t *bullet_list;
    bullets_t **bullet;
    stuff_t *stuff;
    int game_status;
} in_game_t;

typedef struct end_s
{
    sfSprite *road;
    sfIntRect road_rect;
    int road_offset;
    int road_line;
    int wait_road;
    sfSoundBuffer *cine2;
    sfSound *cinematic_2;
    int status_cinematic2;
    sfSprite *credits;
    sfVector2f pos_credits;
} end_t;

#endif /* !gm */
