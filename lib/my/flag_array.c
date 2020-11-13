/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** flag_array
*/

#include "my.h"

int find_flag(char *flag_board, char flag_char)
{
    int flag_nbr = 0;

    for (; flag_board[flag_nbr] != 0; flag_nbr ++) {
        if (flag_board[flag_nbr] == flag_char)
            return (flag_nbr);
    }
    return (-1);
}