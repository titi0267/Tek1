/*
** EPITECH PROJECT, 2021
** check txw
** File description:
** check_two.c
*/

#include "include/solve.h"

void checks_five(read_t *rd)
{
    if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car]
    && rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car - 1] = 'o';
        rd->car--;
    } else if (rd->path[rd->ln + 1][rd->car] != -1 &&
    (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1]
    && rd->path[rd->ln][rd->car - 1] != -1)) {
        rd->line[rd->ln + 1][rd->car] = 'o';
        rd->ln++;
    }
}

void checks_six(read_t *rd)
{
    if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car + 1] = 'o';
        rd->car++;
    } else if (rd->path[rd->ln - 1][rd->car] != 1000000 &&
    (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)) {
        rd->line[rd->ln - 1][rd->car] = 'o';
        rd->ln--;
    }
}

void checks_seven(read_t *rd)
{
    if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)) {
        rd->line[rd->ln][rd->car - 1] = 'o';
        rd->car--;
    } else if (rd->path[rd->ln - 1][rd->car] != 1000000 &&
    (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1]
    && rd->path[rd->ln][rd->car - 1] != -1)) {
        rd->line[rd->ln - 1][rd->car] = 'o';
        rd->ln--;
    }
}

void checks_eight_part_two(read_t *rd)
{
    if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)
    && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car]
    && rd->path[rd->ln - 1][rd->car] != -1)) {
        rd->line[rd->ln + 1][rd->car] = 'o';
        rd->ln++;
    } else {
        if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car]
        && rd->path[rd->ln + 1][rd->car] != -1)
        && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car]
        && rd->path[rd->ln - 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car + 1] = 'o';
            rd->car++;
        }
    }
}

void checks_eight(read_t *rd)
{
    if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1]
    && rd->path[rd->ln][rd->car + 1] != -1)
    && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car]
    && rd->path[rd->ln + 1][rd->car] != -1)) {
        rd->line[rd->ln - 1][rd->car] = 'o';
        rd->ln--;
    } else
        checks_eight_part_two(rd);
}
