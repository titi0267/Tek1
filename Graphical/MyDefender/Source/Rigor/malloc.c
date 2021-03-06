/*
** EPITECH PROJECT, 2021
** malloc by Timothy CONIEL & Trista HOURTOUILLE
** File description:
** malloc.c
*/

#include "../../include/defender.h"

int struct_alloc_bis(core_t *core)
{
    if (core == NULL || core->wnd == NULL || core->time == NULL ||
        core->menu == NULL || core->menu->button == NULL ||
        core->menu->stg == NULL || core->menu->stg->vol == NULL ||
        core->shop == NULL || core->game == NULL || core->enemy == NULL
        || core->enemy->pirat == NULL || core->enemy->data == NULL
        || core->wave == NULL || core->game->defense == NULL ||
        core->game->tower == NULL || core->game->pause == NULL)
        return (ERROR);
    return (0);
}

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
    core->shop = malloc(sizeof(shop_t));
    core->enemy->pirat = malloc(sizeof(pirat_spt_t));
    core->enemy->data = malloc(sizeof(pirat_data_t));
    core->wave = malloc(sizeof(wave_t));
    core->game->defense = malloc(sizeof(defense_t));
    core->game->tower = malloc(sizeof(tower_t));
    core->game->pause = malloc(sizeof(pause_t));

    if (struct_alloc_bis(core) == ERROR)
        return (ERROR);
    return (0);
}