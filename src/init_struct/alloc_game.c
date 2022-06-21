/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** alloc_game
*/

#include "../../include/func_name.h"

int game_malloc(rpg_t *rpg)
{
    int i = 0;

    if ((rpg->game->in_game = malloc(sizeof(in_game_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->ig_sound = malloc(sizeof(ig_sound_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->inventory = malloc(sizeof(inventory_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->map = malloc(sizeof(map_t))) == NULL)
        return (MALLOC_ERROR);
    i++;
    if ((rpg->game->in_game->objects = malloc(sizeof(objects_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->nmi = malloc(sizeof(enemy_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->end = malloc(sizeof(end_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->start = malloc(sizeof(start_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}

int game_malloc2(rpg_t *rpg)
{
    int i = 0;

    if ((rpg->game->in_game->ig_menus = malloc(sizeof(ig_menus_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->map = malloc(sizeof(map_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->objects->car = malloc(sizeof(car_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->phone = malloc(sizeof(phone_t))) == NULL)
        return (MALLOC_ERROR);
    i++;
    if ((rpg->game->in_game->stats = malloc(sizeof(stat_t))) == NULL)
        return (MALLOC_ERROR);
    if (malloc_stat_player(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->particle = malloc(sizeof(particle_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->bullet = malloc(sizeof(bullets_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}

int game_malloc3(rpg_t *rpg)
{
    if ((rpg->game->in_game->stuff = malloc(sizeof(stuff_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}