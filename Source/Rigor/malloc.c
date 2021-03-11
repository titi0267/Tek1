/*
** EPITECH PROJECT, 2021
** malloc by Timothy CONIEL & Trista HOURTOUILLE
** File description:
** malloc.c
*/

#include "../../include/defender.h"

int struct_alloc(core_t *core)
{
    core->wnd = malloc(sizeof(window_t));
    core->time = malloc(sizeof(time_t));
    core->menu = malloc(sizeof(menu_t));
    core->menu->button = malloc(sizeof(button_t));
    core->menu->stg = malloc(sizeof(settings_t));
    core->menu->stg->vol = malloc(sizeof(volume_t));
    core->game = malloc(sizeof(game_t));
    core->enemy = malloc(sizeof(enemy_t));
    core->enemy->pirat = malloc(sizeof(pirat_spt_t));
    core->enemy->data = malloc(sizeof(pirat_data_t));

    if (core == NULL || core->wnd == NULL || core->time == NULL ||
        core->menu == NULL || core->menu->button == NULL ||
        core->menu->stg == NULL || core->menu->stg->vol == NULL ||
        core->game == NULL || core->enemy == NULL || core->enemy->pirat == NULL
        || core->enemy->data == NULL)
        return (ERROR);
    return (0);
}
