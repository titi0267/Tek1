/*
** EPITECH PROJECT, 2021
** main from solver
** File description:
** main
*/

#include "include/solve.h"

int main(int ac, char **av)
{
    solve_t *slv;

    if ((slv = malloc(sizeof(solve_t))) == NULL)
        return (ERROR);
    malloc_struct(slv);
    read_maze(slv->rd, av);
    replace_nbr(slv->rd);
    increment(slv->rd);
    free_func(slv);
    free(slv);
    return (0);
}