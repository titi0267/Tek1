/*
** EPITECH PROJECT, 2021
** check one
** File description:
** check_one.c
*/

#include "include/solve.h"

void checks_one_part_two(read_t *rd)
{
    if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)
    && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)
    && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car]
    && rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car - 1] = 'o';
        rd->car--;
    } else if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1]
    && rd->path[rd->ln][rd->car - 1] != -1)
    && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)
    && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car]
    && rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car + 1] = 'o';
        rd->car++;
    }
}

void checks_one(read_t *rd)
{
    if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1) &&
    (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] &&
    rd->path[rd->ln][rd->car - 1] != -1) &&
    (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] &&
    rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln - 1][rd->car] = 'o';
        rd->ln--;
    } else if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)
    && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] &&
    rd->path[rd->ln][rd->car - 1] != -1)
    && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] &&
    rd->path[rd->ln - 1][rd->car] != -1)) {
        rd->line[rd->ln + 1][rd->car] = 'o';
        rd->ln++;
    } else
        checks_one_part_two(rd);
}

void checks_two(read_t *rd)
{
    if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] &&
    rd->path[rd->ln][rd->car + 1] != -1)
    && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] &&
    rd->path[rd->ln][rd->car - 1] != -1)) {
        rd->line[rd->ln + 1][rd->car] = 'o';
        rd->ln++;
    } else if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)
    && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] &&
    rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car - 1] = 'o';
        rd->car--;
    } else 
        checks_two_next(rd);
}

void checks_three(read_t *rd)
{
    if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)
    && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1]
    && rd->path[rd->ln][rd->car - 1] != -1)) {
        rd->line[rd->ln - 1][rd->car] = 'o';
        rd->ln--;
    } else if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)
    && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car - 1] = 'o';
        rd->car--;
    } else
        checks_three_next(rd);
}

void checks_four(read_t *rd)
{
    if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car]
    && rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car + 1] = 'o';
        rd->car++;
    } else if (rd->path[rd->ln + 1][rd->car] != -1 &&
    (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)) {
        rd->line[rd->ln + 1][rd->car] = 'o';
        rd->ln++;
    }
}
