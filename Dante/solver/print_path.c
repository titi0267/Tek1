    /*
** EPITECH PROJECT, 2021
** print resolved maze
** File description:
** print_path.c
*/

#include "include/solve.h"


void checks_nine(read_t *rd)
{
    if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1]
    && rd->path[rd->ln][rd->car - 1] != -1)
    && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car]
    && rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln - 1][rd->car] = 'o';
        rd->ln--;
    }
    else if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1]
    && rd->path[rd->ln][rd->car - 1] != -1)
    && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)) {
        rd->line[rd->ln + 1][rd->car] = 'o';
        rd->ln++;
    }
    else if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car]
    && rd->path[rd->ln + 1][rd->car] != -1)
    && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car - 1] = 'o';
        rd->car--;
    }
}

void replace_solve_next(read_t *rd)
{
    if (rd->ln == (rd->line_nbr - 1) && rd->car != 0 &&
    rd->car < (rd->char_nbr - 1))
        checks_three(rd);
    else if (rd->ln == (rd->line_nbr - 1) && rd->car == 0)
        checks_six(rd);
    else if (rd->ln == (rd->line_nbr - 1) && rd->car == (rd->char_nbr - 1))
        checks_seven(rd);
    if (rd->car == 0 && rd->ln != 0 && rd->ln < (rd->line_nbr - 1))
        checks_eight(rd);
    if (rd->car == (rd->char_nbr - 1) && rd->ln != 0
    && rd->ln < (rd->line_nbr - 1))
        checks_nine(rd);
}

void replace_solve(read_t *rd)
{
    rd->line[rd->ln][rd->car] = 'o';
    while (rd->ln != 0 || rd->car != 0) {
        if ((rd->ln != 0 && rd->ln < (rd->line_nbr - 1)) && rd->car != 0
        && rd->car < (rd->char_nbr - 1))
            checks_one(rd);
        if (rd->ln == 0 && rd->car != 0 && rd->car < (rd->char_nbr - 1))
            checks_two(rd);
        else if (rd->ln == 0 && rd->car == 0)
            checks_four(rd);
        else if (rd->ln == 0 && rd->car == (rd->char_nbr - 1))
            checks_five(rd);
        replace_solve_next(rd);
    }
}
