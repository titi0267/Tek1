/*
** EPITECH PROJECT, 2021
** change in numbers
** File description:
** number_map.c
*/

#include "include/solve.h"

int replace_nbr(read_t *rd)
{
    int d = 0;

    if ((rd->path = malloc(sizeof(int *) * rd->line_nbr)) == NULL)
        return (ERROR);
    for (int i = 0; rd->line[i] != NULL; i++) {
        if ((rd->path[i] = malloc(sizeof(int) * (rd->char_nbr + 1))) == NULL)
            return (ERROR);
        for (; rd->line[i][d] != '\n'; d++) {
        if (rd->line[i][d] == '*') {
            rd->path[i][d] = 0;
        }
        if (rd->line[i][d] == 'X')
            rd->path[i][d] = 1000000;
        }
        rd->path[i][d] = -2;
        d = 0;
    }
    return (0);
}

void find_path(read_t *rd, int car, int line, int len)
{
    int f = 0;

    if (rd->path[line][car] == len) {
        if (car != 0 && rd->path[line][car - 1] == 0)
            rd->path[line][car - 1] = len + 1;
        if (car < rd->char_nbr - 1 && rd->path[line][car + 1] == 0)
            rd->path[line][car + 1] = len + 1;
        if (line != 0 && rd->path[line - 1][car] == 0)
            rd->path[line - 1][car] = len + 1;
        if (line < rd->line_nbr - 1 && rd->path[line + 1][car] == 0)
            rd->path[line + 1][car] = len + 1;
    }
}

int check_resolved(read_t *rd)
{
    int v = 0;
    int d = 0;

    for (; rd->line[v] != NULL; v++) {
        for (; rd->line[v][d] != '\0'; d++) {
            if (rd->path[v][d] == 0)
                break;
        }
        if (rd->line[v][d] != '\0')
            break;
        d = 0;
    }
    if (rd->line[v] == NULL)
        return (1);
    v = 0;
    return (0);
}

void increment(read_t *rd)
{
    int len = 1;
    int line = 0;

    rd->path[0][0] = 1;
    for (; len < (rd->char_nbr * rd->line_nbr); len++) {
        for (; line < rd->line_nbr; line++) {
            for (int car = 0; car < rd->char_nbr; car++)
                find_path(rd, car, line, len);
        }
        line = 0;
        if (check_resolved(rd) == TRUE) return;
    }
}
