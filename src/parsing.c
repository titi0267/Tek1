/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** parsing
*/

#include "../include/func_name.h"

void parsing_menus(rpg_t *rpg)
{
    static int nbr = 0;

    if (rpg->menu->status == ON_BASIL) {
        start_actions(rpg);
        nbr += rpg->basic->cnf->clk->time_total;
        if (rpg->menu->intro->status == FALSE && nbr > 0.1) {
            init_basic_value(rpg);
            init_function(rpg);
        }
    }
    if (rpg->menu->status == ON_NEW_GM) {
        background(rpg);
        choose_perso(rpg);
    }
    if (rpg->menu->status == ON_OPTION_PAUSE) {
        background(rpg);
        options_exit(rpg);
    }
    if (rpg->menu->status == ON_OPTION) {
        background(rpg);
        options(rpg);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            rpg->menu->status = ON_MENU;
    }
}

void parsing_menu2(rpg_t *rpg)
{
    if (rpg->menu->status == ON_CONTINUE) {
        sfSound_stop(rpg->menu->main_menu->menu_snd->a_menu);
        rpg->menu->main_menu->menu_snd->status_sound_menu = FALSE;
        load_save(rpg);
    }
    if (rpg->menu->status == ON_TUTO) {
        sfSound_stop(rpg->menu->main_menu->menu_snd->a_menu);
        rpg->game->in_game->map->status = MAP_TUTO;
        rpg->menu->main_menu->menu_snd->status_sound_menu = FALSE;
        ambiant_tuto(rpg);
        tuto1(rpg);
        if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
        (rpg->basic->evt->event.text.unicode == 'p'))
            rpg->menu->status = ON_MENU;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            rpg->menu->status = ON_OPTION;
    }
    if (rpg->menu->status == ON_EXIT) {
        chose_map(rpg);
        assemble_spt_pause(rpg);
    }
}

void parsing_menu3(rpg_t *rpg)
{
    if (rpg->menu->status == ON_GAME) {
        sfRenderWindow_clear(rpg->basic->wnd->my_wnd, sfBlack);
        if (rpg->game->in_game->map->status != MAP_INSIDE_POLICE)
            ambiant_game(rpg);
        if (rpg->game->in_game->map->status == MAP_INSIDE_POLICE)
            sfSound_stop(rpg->game->in_game->ig_sound->game);
        parsing_avance(rpg);
        rpg->menu->main_menu->menu_snd->status_sound_menu = FALSE;
    }
    if (rpg->menu->status == ON_INVENTORY) {
        chose_map(rpg);
        display_inventory(rpg);
        key_event_inventory(rpg);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            rpg->menu->status = ON_GAME;
    }
}

int parsing_menu4(rpg_t *rpg)
{
    if (rpg->menu->status == ON_MENU) {
        sound(rpg, 2);
        background(rpg);
        sfSound_stop(rpg->tutorial->tuto);
        sfSound_stop(rpg->game->in_game->ig_sound->game);
        if (main_menu(rpg) == -1)
            return (-1);
        rpg->basic->cnf->clk->time_menu = 0;
        rpg->tutorial->status_sound_tuto = FALSE;
        rpg->game->in_game->ig_sound->status_sound_game = FALSE;
    }
    if (rpg->menu->status == ON_CINEMATIC1) {
        sfSound_stop(rpg->menu->main_menu->menu_snd->a_menu);
        cinematic_1(rpg);
        if (sfSound_getStatus(rpg->game->start->cinematic_1) != sfPlaying) {
            rpg->menu->status = ON_GAME;
            rpg->game->in_game->game_status = GM_BEGIN;
        }
    }
    return (0);
}

int parsing(rpg_t *rpg)
{
    parsing_menus(rpg);
    parsing_menu2(rpg);
    parsing_menu3(rpg);
    if (parsing_menu4(rpg) == -1)
        return (-1);
    return (0);
}