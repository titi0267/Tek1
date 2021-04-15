/*
** EPITECH PROJECT, 2021
** enum.h
** File description:
** enum
*/

#ifndef enumeration
#define enumeration

typedef enum stg_status_s {
    GRAPH_SCN,
    SOUND_SCN,
    KEYS_SCN
} stg_status_t;

typedef enum rpg_status_s {
    ON_BASIL,
    ON_PEGI,
    ON_MENU,
    ON_OPTION,
    ON_NEW_GM,
    ON_TUTO,
    ON_CONTINUE
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

#endif /* !enumeration */
