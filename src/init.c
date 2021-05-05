/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init
*/

#include "../include/func_name.h"

void init_basic_value2(rpg_t *rpg)
{
    rpg->game->in_game->phone->phone_status = 1;
    rpg->game->in_game->phone->notif_bool = FALSE;
    rpg->game->in_game->phone->call_status = FALSE;
    rpg->game->start->status_cinematic1 = FALSE;
    rpg->game->in_game->phone->notif_index = 0;
    rpg->game->in_game->phone->notif_prev = 0;
    rpg->game->in_game->stats->xp_value = 0;
    rpg->game->in_game->stats->level_up = 0;
    rpg->game->in_game->particle->xp = malloc(sizeof(sfVector2f) * 7);
    rpg->game->in_game->particle->blood = malloc(sizeof(sfVector2f) * 5);
    *(rpg->game->in_game->nmi) = NULL;
    rpg->basic->cnf->clk->direction_clk = 1;
}

void init_basic_value(rpg_t *rpg)
{
    rpg->basic->cnf->clk->time_keyboard = 0;
    rpg->basic->cnf->clk->time_tutorial = 0;
    rpg->basic->cnf->clk->time_car = 0;
    rpg->basic->cnf->clk->time_shortcut = 0;
    rpg->menu->stg->stg_scene = GRAPH_SCN;
    rpg->game->in_game->inventory->shortcut_it = INVENTORY_OFF;
    rpg->game->in_game->map->last_pos = -1;
    rpg->game->in_game->objects->speed_status = WALK_SPEED;
    rpg->game->in_game->ig_sound->status_sound_game = FALSE;
    rpg->tutorial->tutorial_stat = TUTO1;
    rpg->tutorial->status_sound_tuto = FALSE;
    rpg->game->in_game->phone->alarm_status = FALSE;
    rpg->game->in_game->game_status = -1;
    init_basic_value2(rpg);
}

int init_before_game(rpg_t *rpg)
{
    create_window(rpg->basic);
    if (init_tuto(rpg) == 84 || realrandom() == 84 ||
    init_pdown_up_rect(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    init_logo_spt(rpg);
    init_pegi_spt(rpg);
    create_boom(rpg->menu);
    rpg->basic->cnf->clk->clock = sfClock_create();
    rpg->basic->cnf->scr_cnf->fps = 60;
    rpg->basic->cnf->clk->time_total = 0;
    rpg->basic->cnf->clk->time_loop = 0;
    rpg->basic->cnf->scr_cnf->resolution = 0;
    rpg->menu->status = ON_BASIL;
    rpg->menu->intro->status = FALSE;
    rpg->menu->main_menu->menu_snd->status_sound_menu = FALSE;
    rpg->menu->intro->window_access = TRUE;
    return (0);
}

void init_function2(rpg_t *rpg)
{
    create_police_map(rpg);
    init_car_spt(rpg);
    init_amb_tuto_game(rpg);
    init_phone(rpg);
    init_phone_sound(rpg);
    init_pitch_riley(rpg);
    init_stats_value(rpg);
    init_xplife(rpg);
    init_particle(rpg);
}

void init_function(rpg_t *rpg)
{
    init_main_menu(rpg);
    init_rect_adn(rpg);
    init_controls(rpg);
    init_option1(rpg);
    create_size_square(rpg);
    sound_cirle(rpg);
    init_bt_opt(rpg);
    init_new_game(rpg);
    init_characters_sprites(rpg);
    init_inventory(rpg);
    init_pause(rpg);
    init_exit_option1(rpg);
    init_cinematic1_audio(rpg);
    init_radio_spt(rpg);
    init_function2(rpg);
    rpg->menu->intro->status = TRUE;
}