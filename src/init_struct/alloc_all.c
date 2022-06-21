/*
** EPITECH PROJECT, 2021
** alloc all struct
** File description:
** malloc
*/

#include "../../include/func_name.h"

int alloc_all(rpg_t *rpg)
{
    int i = 0;
    if (first_alloc(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if (basic_malloc(rpg->basic) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if (menu_alloc(rpg->menu) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if (menu_alloc_next(rpg->menu) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    i++;
    if (game_malloc(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if (game_malloc2(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if (game_malloc3(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    return (0);
}