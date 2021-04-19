/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** parsing
*/

#include "../include/func_name.h"

void sound(rpg_t *rpg, int status)
{
    static int sound1 = 0;
    static int sound2 = 0;

    if (sound1 == 0 && status == 1) {
        sfSound_play(rpg->menu->intro->intro_snd->start);
        sound1 = 1;
    }
    if ((sound2 == 0) && status == 2) {
        sfSound_stop(rpg->menu->intro->intro_snd->start);
        sfSound_play(rpg->menu->main_menu->menu_snd->a_menu);
        sound2 = 1;
    }
}

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
            rpg->menu->status = ON_PEGI;
        nbr += rpg->basic->cnf->clk->time_loop;
    }
    if (rpg->menu->status == ON_PEGI) {
        sound(rpg, 2);
        background(rpg);
        main_menu(rpg);
    }
}

void parsing_menu2(rpg_t *rpg)
{
    // if (rpg->menu->status == ON_NEW_GM) // New game
    // if (rpg->menu->status == ON_CONTINUE) // Continue game
    // if (rpg->menu->status == ON_TUTO) // Tutoriel
    if (rpg->menu->status == ON_OPTION) {
        background(rpg);
        options(rpg);
    }
}

int parsing(rpg_t *rpg)
{
    parsing_menus(rpg);
    parsing_menu2(rpg);
}