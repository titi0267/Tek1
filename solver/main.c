/*
** EPITECH PROJECT, 2021
** main from solver
** File description:
** main
*/

#include "include/solve.h"

int malloc_struct(solve_t *slv)
{
    read_t *rd = malloc(sizeof(read_t));
}

int main(int ac, char **av)
{
    solve_t *slv = malloc(sizeof(solve_t));

    if (slv == NULL)
        return (ERROR);
    malloc_struct(slv);
    return (0);
}