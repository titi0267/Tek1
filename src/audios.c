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

    if (sound1 == 0 && status == 1) {
        sfSound_play(rpg->menu->intro->intro_snd->start);
        sound1 = 1;
    }
    if ((rpg->menu->main_menu->menu_snd->status_sound_menu == FALSE)
    && status == 2) {
        sfSound_stop(rpg->menu->intro->intro_snd->start);
        sfSound_play(rpg->menu->main_menu->menu_snd->a_menu);
        rpg->menu->main_menu->menu_snd->status_sound_menu = TRUE;
    }
}

void ambiant_tuto(rpg_t *rpg)
{
    if (rpg->tutorial->status_sound_tuto == FALSE) {
        sfSound_play(rpg->tutorial->tuto);
        rpg->tutorial->status_sound_tuto = TRUE;
    }
}

void ambiant_game(rpg_t *rpg)
{
    if (rpg->game->in_game->ig_sound->status_sound_game == FALSE) {
        sfSound_play(rpg->game->in_game->ig_sound->game);
        rpg->game->in_game->ig_sound->status_sound_game = TRUE;
    }
}