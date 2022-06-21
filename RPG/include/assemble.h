/*
** EPITECH PROJECT, 2021
** assemble big structs
** File description:
** assemble
*/

#ifndef assemble
#define assemble

#include "basics.h"
#include "menu.h"
#include "settings.h"
#include "game.h"
#include "rpg_enum.h"

typedef struct tutorial_s
{
    sfSprite **instruct;
    sfSoundBuffer *amb_tuto;
    sfSound *tuto;
    int tutorial_stat;
    int status_sound_tuto;
} tutorial_t;

typedef struct game_s
{
    start_t *start;
    in_game_t *in_game;
    end_t *end;
} game_t;

typedef struct basic_s
{
    config_t *cnf;
    event_t *evt;
    window_t *wnd;
} basic_t;

typedef struct menu_s
{
    intro_t *intro;
    main_menu_t *main_menu;
    setting_t *stg;
    background_adn_t *bgd_adn;
    int status;
} menu_t;

typedef struct rpg_s {
    basic_t *basic;
    game_t *game;
    menu_t *menu;
    tutorial_t *tutorial;
} rpg_t;

#endif /* !assemble */
