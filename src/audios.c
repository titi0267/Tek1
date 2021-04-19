/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** audios
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