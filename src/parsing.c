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
        main_menu(rpg);
    }
}

void parsing_menu2(rpg_t *rpg)
{
    if (rpg->menu->status == ON_NEW_GM) {
        background(rpg);
        choose_perso(rpg);
    }
    if (rpg->menu->status == ON_CONTINUE) {

    }
    if (rpg->menu->status == ON_TUTO) {

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

}

int parsing(rpg_t *rpg)
{
    parsing_menus(rpg);
    parsing_menu2(rpg);
}