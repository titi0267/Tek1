/*
** EPITECH PROJECT, 2021
** init and end solver
** File description:
** init_end.c
*/

#include "include/solve.h"

int malloc_struct(solve_t *slv)
{
    slv->rd = malloc(sizeof(read_t));

    if (slv->rd == NULL)
        return (ERROR);
}

void free_func(solve_t *slv)
{
    for (int i = 0; slv->rd->line[i] != NULL; i++) {
        free(slv->rd->line[i]);
    }
    free(slv->rd->line);
    free(slv->rd->buffer);
    free(slv->rd);
}
