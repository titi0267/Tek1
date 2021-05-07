/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** rpg
*/

#include "../include/func_name.h"

int main_parsing(rpg_t *rpg)
{
    parsing_1(rpg);
    parsing_2(rpg);
    parsing_3(rpg);
    if (parsing_4(rpg) == -1)
        return (-1);
    parsing_4(rpg);
    parsing_5(rpg);
    return (0);
}

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