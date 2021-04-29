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
    if ((rpg->game->in_game->txt = malloc(sizeof(txt_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->end = malloc(sizeof(end_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->start = malloc(sizeof(start_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}

int game_malloc2(rpg_t *rpg)
{
    if ((rpg->game->in_game->ig_menus = malloc(sizeof(ig_menus_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->map = malloc(sizeof(map_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game->in_game->objects->car = malloc(sizeof(car_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}