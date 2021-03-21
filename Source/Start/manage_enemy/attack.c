/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** attack
*/

#include "../../../include/defender.h"

int attack_bis(core_t *core)
{
    if (core->wave->end_game == 0) {
        sfSound_play(core->menu->stg->vol->gameover);
        core->wave->end_game = 1;
        while (sfSound_getStatus(core->menu->stg->vol->gameover) == sfPlaying);
    } else if (core->wave->end_game == 1) {
        sfSound_play(core->menu->stg->vol->laugh);
        core->wave->end_game = 2;
        while (sfSound_getStatus(core->menu->stg->vol->laugh) == sfPlaying);
    } else if (core->wave->end_game == 2) {
        init(core);
        core->menu->menu_bg = TRUE;
        core->menu->pause_on = FALSE;
        core->menu->game_bgd = FALSE;
        return (1);
    }
    return (0);
}

int attack(core_t *core, pirat_data_t *data)
{
    int tmp = 0;

    data->dead = 1;
    if ((core->game->lifepoint - 5) <= 0) {
        while (tmp == 0)
            tmp = attack_bis(core);
    } else
        core->game->lifepoint -= 5;
    return (0);
}