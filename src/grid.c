/*
** EPITECH PROJECT, 2020
** grid by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** grid.c
*/
#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>


int char_column(char c)
{
    switch(c) {
    case 'A':
        return (2);
    case 'B':
        return (4);
    case 'C':
        return (6);
    case 'D':
        return (8);
    case 'E':
        return (10);
    case 'F':
        return (12);
    case 'G':
        return (14);
    case 'H':
        return (16);
    default:
        return (-1);
    }
}

int char_line(char c)
{
    switch(c) {
    case '1':
        return (2);
    case '2':
        return (3);
    case '3':
        return (4);
    case '4':
        return (5);
    case '5':
        return (6);
    case '6':
        return (7);
    case '7':
        return (8);
    case '8':
        return (9);
    default:
        return (-1);
    }
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

int map_p1(map_t *buff, pos_t *where)
{
    which_column(where);
    which_line(where);
    //printf("The 5 ship ends in column %i and line %i\n", where->column_end[3], where->line_end[3]);
    return (0);
}
