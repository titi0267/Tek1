/*
** EPITECH PROJECT, 2021
** error entry
** File description:
** error_entry.c
*/

#include "include/solve.h"

int error_entry(read_t *rd)
{
    if (rd->line[0][0] != '*' ||
    rd->line[rd->line_nbr - 1][rd->char_nbr - 1] != '*')
        return (ERROR);
    else
        return (0);
}