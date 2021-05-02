/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** parsing
*/

#include "../include/func_name.h"

int parsing_menus(rpg_t *rpg)
{
    static float nbr = 0;

    if (rpg->menu->status == ON_BASIL) {
        sound(rpg, 1);
        if (nbr > 1 && nbr < 9.2)
            move_basil(rpg);
        if (nbr > 9.2 && nbr < 10.5)
            sfRenderWindow_clear(rpg->basic->wnd->my_wnd, sfBlack);
        if (nbr > 10.5 && nbr < 17.7)
            background_pegi(rpg);
        if (nbr > 17.7)
            rpg->menu->status = ON_MENU;
        nbr += rpg->basic->cnf->clk->time_loop;
    }
    if (rpg->menu->status == ON_MENU) {
        sound(rpg, 2);
        background(rpg);
        sfSound_stop(rpg->tutorial->tuto);
        if (main_menu(rpg) == -1)
            return (-1);
        rpg->basic->cnf->clk->time_menu = 0;
    }
    return (0);
}

void parsing_menu2(rpg_t *rpg)
{
    if (rpg->menu->status == ON_NEW_GM) {
        background(rpg);
        choose_perso(rpg);
    }
    if (rpg->menu->status == ON_CONTINUE) {
        sfSound_stop(rpg->menu->main_menu->menu_snd->a_menu);
        load_save(rpg);
    }
    if (rpg->menu->status == ON_TUTO) {
        sfSound_stop(rpg->menu->main_menu->menu_snd->a_menu);
        rpg->game->in_game->map->status = MAP_TUTO;
        ambiant_tuto(rpg);
        tuto1(rpg);
        if (rpg->basic->evt->event.text.unicode == 'p')
            rpg->menu->status = ON_MENU;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            rpg->menu->status = ON_OPTION;
    }
    if (rpg->menu->status == ON_OPTION) {
        background(rpg);
        options(rpg);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            rpg->menu->status = ON_MENU;
    }
}

void parsing_menu3(rpg_t *rpg)
{
    if (rpg->menu->status == ON_GAME) {
        sfRenderWindow_clear(rpg->basic->wnd->my_wnd, sfBlack);
        key_event_game(rpg);
        chose_map(rpg);
    }
    if (rpg->menu->status == ON_INVENTORY) {
        chose_map(rpg);
        display_inventory(rpg);
        key_event_inventory(rpg);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            rpg->menu->status = ON_GAME;
    }
    if (rpg->menu->status == ON_EXIT) {
        chose_map(rpg);
        assemble_spt_pause(rpg);
    }
    if (rpg->menu->status == ON_OPTION_PAUSE) {
        background(rpg);
        options_exit(rpg);
    }
}

void parsing_menu4(rpg_t *rpg)
{
    if (rpg->menu->status == ON_CINEMATIC1) {
        sfSound_stop(rpg->menu->main_menu->menu_snd->a_menu);
        cinematic_1(rpg);
        if (sfSound_getStatus(rpg->game->start->cinematic_1) != sfPlaying)
            rpg->menu->status = ON_GAME;
    }
}

int parsing(rpg_t *rpg)
{
    if (parsing_menus(rpg) == -1)
        return (-1);
    parsing_menu2(rpg);
    parsing_menu3(rpg);
    parsing_menu4(rpg);
    return (0);
}