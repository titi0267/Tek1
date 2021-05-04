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
} start_t;

typedef struct inventory_s {
    sfSprite *inventory;
    sfTexture *inventory_txt;
    sfSprite **weapon;
    sfTexture **weapon_txt;
    sfVector2f *pos_weapon;
    int shortcut_it;
    int is_item_selected;
    int *is_area_filled;
    int on_click;
    int valid;
    int selected_item;
    sfVector2f *pos_storage;
    sfFloatRect *glob_pos;
    int click_weapon;
    int release_weapon;
    sfVector2i **box_pos;
    int on_drag;
} inventory_t;

typedef struct ig_sound_s
{
    sfSoundBuffer *amb_game;
    sfSound *game;
    int status_sound_game;
    sfSound *riley;
    sfSound *riley_call;
} ig_sound_t;

typedef struct car_s
{
    sfSprite *car;
    sfIntRect rect_car;
    sfVector2f car_pos;
    int car_line;
    int status;
} car_t;

typedef struct objects_s
{
    sfSprite **players;
    sfTexture **player_tex;
    car_t *car;
    int speed_status;
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
    int status;
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
    sfSound *call_sound;
    int phone_status;
    int notif_index;
    int notif_bool;
    int notif_prev;
} phone_t;

typedef struct player_stats_s
{
    sfText *txt;
    int value;
} player_stats_t;

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
    player_stats_t **player_stats;
    int game_status;
} in_game_t;

typedef struct end_s
{

} end_t;

#endif /* !gm */
