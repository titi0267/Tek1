/*
** EPITECH PROJECT, 2020
** place_ship by Timothy CONIEL & Elliot WALVOGEL
** File description:
** place_ship.c
*/
#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

int which_line2(pos_t *where)
{
    int f = 0;
    int i = 0;
    int x = -1;

    where->line_start2 = malloc(sizeof(int) * 5);
    where->line_end2 = malloc(sizeof(int) * 5);
    while (f != 4) {
        x = char_line(where->find_pos2[f][3]);
        if (x != -1)
            where->line_start2[i] = x;
        x = char_line(where->find_pos2[f][6]);
        if (x != -1)
            where->line_end2[i] = x;
        f++;
        i++;
    }
    return (0);
}

int which_line(pos_t *where)
{
    int f = 0;
    int i = 0;
    int x = -1;

    where->line_start = malloc(sizeof(int) * 5);
    where->line_end = malloc(sizeof(int) * 5);
    while (f != 4) {
        x = char_line(where->find_pos1[f][3]);
        if (x != -1)
            where->line_start[i] = x;
        x = char_line(where->find_pos1[f][6]);
        if (x != -1)
            where->line_end[i] = x;
        f++;
        i++;
    }
    return (0);
}

int which_column(pos_t *where)
{
    int f = 0;
    int i = 0;
    int x = -1;

    where->column_start = malloc(sizeof(int) * 5);
    where->column_end = malloc(sizeof(int) * 5);
    while (f != 4) {
        x = char_column(where->find_pos1[f][2]);
        if (x != -1)
            where->column_start[i] = x;
        x = char_column(where->find_pos1[f][5]);
        if (x != -1)
            where->column_end[i] = x;
        f++;
        i++;
    }
    return (0);
}

int which_column2(pos_t *where)
{
    int f = 0;
    int i = 0;
    int x = -1;

    where->column_start2 = malloc(sizeof(int) * 5);
    where->column_end2 = malloc(sizeof(int) * 5);
    while (f != 4) {
        x = char_column(where->find_pos2[f][2]);
        if (x != -1)
            where->column_start2[i] = x;
        x = char_column(where->find_pos2[f][5]);
        if (x != -1)
            where->column_end2[i] = x;
        f++;
        i++;
    }
    return (0);
}