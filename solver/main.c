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
    slv->rd->ln = slv->rd->line_nbr - 1;
    slv->rd->car = slv->rd->char_nbr - 1;
    replace_solve(slv->rd);
    for (int i = 0; slv->rd->line[i] != NULL; i++) {
        for (int d = 0; slv->rd->line[i][d] != '\0'; d++) {
            if (i == slv->rd->line_nbr - 1 && slv->rd->line[i][d] == '\n')
                break;
            else
                my_printf("%c", slv->rd->line[i][d]);
        }
    }
    free_func(slv);
    free(slv);
    return (0);
}