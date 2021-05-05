/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** rpg
*/

#include "../include/func_name.h"

int main(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (rpg == NULL)
        return (MALLOC_ERROR);
    if (alloc_all(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if (init_before_game(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if (rpg->menu->intro->window_access == TRUE)
        open_window(rpg);
    destroy_all(rpg);
    free_all(rpg);
    free(rpg);
    return (0);
}