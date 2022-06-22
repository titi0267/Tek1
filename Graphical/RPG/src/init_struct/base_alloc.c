/*
** EPITECH PROJECT, 2021
** init base of struct
** File description:
** base_init.c
*/

#include "../../include/func_name.h"

int first_alloc(rpg_t *rpg)
{
    if ((rpg->basic = malloc(sizeof(basic_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->menu = malloc(sizeof(menu_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->game = malloc(sizeof(game_t))) == NULL)
        return (MALLOC_ERROR);
    if ((rpg->tutorial = malloc(sizeof(tutorial_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}