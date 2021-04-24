/*
** EPITECH PROJECT, 2021
** check three
** File description:
** check_next.c
*/

#include "include/solve.h"

void checks_three_next(read_t *rd)
{
    if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1]
    && rd->path[rd->ln][rd->car - 1] != -1)
    && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car + 1] = 'o';
        rd->car++;
    }
}

void checks_two_next(read_t *rd)
{
    if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1]
    && rd->path[rd->ln][rd->car - 1] != -1)
    && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] &&
    rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car + 1] = 'o';
        rd->car++;
    }
}
