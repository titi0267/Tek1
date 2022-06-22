/*
** EPITECH PROJECT, 2021
** main from solver
** File description:
** main
*/

#include "include/solve.h"

void print_solved_maze(solve_t *slv)
{
    for (int i = 0; slv->rd->line[i] != NULL; i++) {
        for (int d = 0; slv->rd->line[i][d] != '\0'; d++) {
            if (i == slv->rd->line_nbr - 1 && slv->rd->line[i][d] == '\n')
                break;
            else
                my_printf("%c", slv->rd->line[i][d]);
        }
    }
}

int main(int ac, char **av)
{
    solve_t *slv;

    if ((slv = malloc(sizeof(solve_t))) == NULL)
        return (ERROR);
    if (malloc_struct(slv) == ERROR || read_maze(slv->rd, av) == ERROR ||
    replace_nbr(slv->rd) == ERROR)
        return (ERROR);
    increment(slv->rd);
    slv->rd->ln = slv->rd->line_nbr - 1;
    slv->rd->car = slv->rd->char_nbr - 1;
    replace_solve(slv->rd);
    print_solved_maze(slv);
    free_func(slv);
    free(slv);
    return (0);
}