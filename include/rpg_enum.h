/*
** EPITECH PROJECT, 2021
** enum.h
** File description:
** enum
*/

#ifndef enumeration
#define enumeration
#define TRUE 1
#define FALSE 0

typedef enum stg_status_s {
    GRAPH_SCN,
    SOUND_SCN,
    KEYS_SCN
} stg_status_t;

typedef enum rpg_status_s {
    ON_BASIL,
    ON_MENU,
    ON_OPTION,
    ON_NEW_GM,
    ON_TUTO,
    ON_CONTINUE,
    ON_GAME,
    ON_INVENTORY,
    ON_EXIT,
    ON_OPTION_PAUSE,
    ON_CINEMATIC1,
    ON_CINEMATIC2
} rpg_status_t;

typedef enum spt_btn_s {
    NEW_GAME,
    CONTINUE,
    TUTORIAL,
    OPTIONS,
    QUIT,
    NONE
} spt_btn_t;

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

typedef enum characters_selection_s {
    MAXOU,
    TIMO,
    LUDO,
    SYLVIE,
    NO_CHARACTERS
} characters_selection_t;

typedef enum sound_gestion_s {
    ON_MUSIC,
    ON_DIAL,
    ON_AMBI
} sound_gestion_t;

typedef enum weapons_s {
    SMG,
    KNIFE,
    GUN,
    TAZER,
    NO_WEAPON,
    BPVEST,
    NO_VEST,
    VACCINE,
    BULLET_1,
    BULLET_2,
    NO_BULLET
} weapons_t;

typedef enum key_status_s {
    INVENTORY_ON,
    INVENTORY_OFF
} key_status_t;

typedef enum pause_place_s {
    RESUME_PAUSE,
    OPTION_PAUSE,
    QUIT_PAUSE,
    MENU_PAUSE,
    NO_BUTTON_PAUSE
} pause_place_t;

typedef enum tuto_s {
    TUTO1,
    TUTO2,
    TUTO3,
    TUTO4,
    TUTO5
} tuto_t;

typedef enum controle_text_s {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    RUN,
    INVENTORY,
    CELLPHONE,
    CAR,
    QUADCOPTER
} controle_text_t;

typedef enum map_enum_s {
    MAP_INSIDE_POLICE,
    MAP_OUTSIDE_POLICE,
    MAP_TUTO,
    MAP_WARREN,
    MAP_OUTSIDE_CDC,
    MAP_OUTSIDE_DISCO,
    MAP_INSIDE_CDC,
    NO_MAP
} map_enum_t;

typedef enum inventory_slots_s {
    WEAPON,
    AMMO,
    VEST,
    NO_SLOT
} inventory_slots_t;

typedef enum collisions_s {
    COL,
    MASK,
    PASS
} collision_t;

typedef enum speed_s {
    WALK_SPEED,
    RUN_SPEED,
    CAR_SPEED
} speed_t;

typedef enum game_avance_s {
    GM_BEGIN,
    GM_SPEECH,
    GM_NOTIF2,
    GM_INCOMMING_CALL,
    GM_CALL,
    GM_NOTIF3,
    GM_NOTIF4,
    GM_NOTIF5,
    GM_NOTIF6,
    GM_RILEY_WARREN,
    GM_NOTIF7,
    GM_ELEVATOR
} game_avance_t;

typedef enum notifs_s {
    NOTIF_MARTINEZ,
    NOTIF1,
    NOTIF2,
    INCOMMING_CALL,
    CALL,
    NOTIF3,
    NOTIF4,
    NOTIF5,
    NOTIF6,
    NOTIF7,
    NOTIF8,
    NO_NOTIF
} notifs_t;

typedef enum stats_s {
    P_LIFE,
    P_DAMAGE,
    P_ARMOR
} stats_t;

#endif /* !enumeration */