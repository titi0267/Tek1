/*
** EPITECH PROJECT, 2020
** match_case by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** match_case.c
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

int map_p1(pos_t *where)
{
    which_column(where);
    which_line(where);
    return (0);
}

int map_p2(pos_t *where)
{
    which_column2(where);
    which_line2(where);
    return (0);
}
