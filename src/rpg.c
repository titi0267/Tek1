/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** rpg
*/

#include "../include/func_name.h"

void init_basic_value2(rpg_t *rpg)
{
    rpg->game->in_game->phone->phone_status = 1;
    rpg->game->in_game->phone->notif_bool = FALSE;
    rpg->game->in_game->phone->notif_index = 0;
    rpg->game->in_game->phone->notif_prev = 0;
}

void init_basic_value(rpg_t *rpg)
{
    rpg->basic->cnf->clk->clock = sfClock_create();
    rpg->basic->cnf->scr_cnf->fps = 60;
    rpg->basic->cnf->clk->time_total = 0;
    rpg->basic->cnf->clk->time_loop = 0;
    rpg->basic->cnf->clk->time_keyboard = 0;
    rpg->basic->cnf->clk->time_tutorial = 0;
    rpg->basic->cnf->clk->time_car = 0;
    rpg->basic->cnf->clk->time_shortcut = 0;
    rpg->menu->main_menu->menu_snd->status_sound_menu = FALSE;
    rpg->menu->stg->stg_scene = GRAPH_SCN;
    rpg->menu->status = ON_BASIL;
    rpg->basic->cnf->scr_cnf->resolution = 0;
    rpg->game->in_game->inventory->shortcut_it = INVENTORY_OFF;
    rpg->game->in_game->map->last_pos = -1;
    rpg->game->in_game->objects->speed_status = WALK_SPEED;
    rpg->game->in_game->ig_sound->status_sound_game = FALSE;
    rpg->tutorial->tutorial_stat = TUTO1;
    rpg->tutorial->status_sound_tuto = FALSE;
    rpg->game->in_game->game_status = -1;
    init_basic_value2(rpg);
}

void init_function2(rpg_t *rpg)
{
    init_pause(rpg);
    init_exit_option1(rpg);
    init_cinematic1_audio(rpg);
    init_radio_spt(rpg);
    create_police_map(rpg);
    init_car_spt(rpg);
    init_amb_tuto_game(rpg);
    init_phone(rpg);
    init_phone_sound(rpg);
    init_pitch_riley(rpg);
}

int init_function(rpg_t *rpg)
{
    init_controls(rpg);
    init_rect_adn(rpg);
    init_main_menu(rpg);
    init_logo_spt(rpg);
    init_pegi_spt(rpg);
    create_boom(rpg->menu);
    init_option1(rpg);
    create_size_square(rpg);
    sound_cirle(rpg);
    init_bt_opt(rpg);
    init_new_game(rpg);
    init_characters_sprites(rpg);
    init_inventory(rpg);
    if (init_tuto(rpg) == 84 || realrandom() == 84 ||
        init_pdown_up_rect(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    init_function2(rpg);
    return (0);
}

int main(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (rpg == NULL)
        return (MALLOC_ERROR);
    if (alloc_all(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    init_basic_value(rpg);
    if (init_function(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    open_window(rpg);
    destroy_all(rpg);
    free_all(rpg);
    free(rpg);
    return (0);
}