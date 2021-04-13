/*
** EPITECH PROJECT, 2021
** alloc all struct
** File description:
** malloc
*/

#include "../../include/func_name.h"

int alloc_all(rpg_t *rpg)
{
    if (first_alloc(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if (basic_malloc(rpg->basic) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    return (0);
}