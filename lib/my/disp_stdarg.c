/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-bsmyprintf-timothe.coniel
** File description:
** disp_stdarg
*/
#include "my.h"
#include <stdarg.h>
#include <unistd.h>

void  my_printf(char *str, ...)
{
    void (*functionName[4]) (va_list *) = {print_str, print_char, print_nbr, print_nbr};
    char flag_board[5] = {'s', 'c', 'd', 'i', 0};
    va_list argu_list;
    int flag_nbr = 0;

    va_start(argu_list, str);
    for (int arr = 0; str[arr] != 0; arr ++) {
        if (arr != 0 && str[arr - 1] == '%') {
            flag_nbr = find_flag(flag_board, str[arr]);
            if (flag_nbr != -1)
                (*functionName[flag_nbr]) (&argu_list);
        } else if (str[arr] != '%') {
            write(1, &str[arr], 1);
        }
    }
}