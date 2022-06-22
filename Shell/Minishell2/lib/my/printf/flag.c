/*
** EPITECH PROJECT, 2020
** Find Right Flag by Timothy CONIEL
** File description:
** flag.c
*/
#include "myp.h"

int find_flag(char *flag_board, char flag_char)
{
    int flag_nbr = 0;

    for (; flag_board[flag_nbr] != 0; flag_nbr ++) {
        if (flag_board[flag_nbr] == flag_char)
            return (flag_nbr);
    }
    return (-1);
}
