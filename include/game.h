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
} inventory_t;

typedef struct ig_sound_s
{

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

typedef struct txt_s
{

} txt_t;

typedef struct ig_menus_s
{
    sfSprite *exit;
    sfSprite **pause_menu;
} ig_menus_t;

typedef struct in_game_s
{
    ig_sound_t *ig_sound;
    objects_t *objects;
    inventory_t *inventory;
    map_t *map;
    txt_t *txt;
    ig_menus_t *ig_menus;
} in_game_t;

typedef struct end_s
{

} end_t;

#endif /* !gm */
