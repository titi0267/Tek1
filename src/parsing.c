/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** parsing
*/

#include "../include/rpg.h"

void sound(rpg_t *rpg, int status)
{
    static int sound1 = 0;
    static int sound2 = 0;

    if (sound1 == 0 && status == 1) {
        sfSound_play(rpg->main_menu->start);
        sound1 = 1;
    }
    if ((sfSound_getStatus(rpg->main_menu->start) == sfStopped) &&
    (sound2 == 0)) {
        sfSound_play(rpg->main_menu->a_menu);
        sound2 = 1;
    }
}

int parsing_menus(rpg_t *rpg)
{
    static float nbr = 0;

    sound(rpg, 1);
    if (rpg->status == 0) {
        if (nbr > 1 && nbr < 9.2)
            move_basil(rpg);
        if (nbr > 9.2 && nbr < 10.5)
            sfRenderWindow_clear(rpg->basics->my_window, sfBlack);
        if (nbr > 10.5 && nbr < 17.7)
            background_pegi(rpg);
        if (nbr > 17.7)
            rpg->status = 1;
        nbr += rpg->basics->time_loop;
    }
    if (rpg->status == 1) {
        background(rpg);
        main_menu(rpg);
    }
}

void parsing_menu2(rpg_t *rpg)
{
    // if (rpg->status == 2) // New game
    // if (rpg->status == 3) // Continue game
    // if (rpg->status == 4) // Tutoriel
    if (rpg->status == 5) { // Options
        background(rpg);
        options(rpg);
    }
}

int parsing(rpg_t *rpg)
{
    parsing_menus(rpg);
    parsing_menu2(rpg);
}