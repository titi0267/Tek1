/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-bsmyprintf-timothe.coniel
** File description:
** disp_stdarg
*/
#include "my.h"
#include <stdarg.h>
#include <unistd.h>

void my_printf(char *str, ...)
{
    void (*functionName[9]) (va_list *) = {print_bin, print_char, print_nbr, print_nbr, print_percent, print_unsigned, print_str, disp_oct, disp_hex};
    char flag_board[10] = {'b', 'c', 'd', 'i', '%', 'u', 's', 'o', 'h', 0};
    va_list argu_list;
    int flag_nbr = 0;

    va_start(argu_list, str);
    for (int arr = 0; str[arr] != 0; arr ++) {
        if (arr != 0 && str[arr - 1] == '%' && str[arr] != ' ') {
            flag_nbr = find_flag(flag_board, str[arr]);
            if (flag_nbr != -1)
                (*functionName[flag_nbr]) (&argu_list);
        } else if (str[arr] != '%')
            write(1, &str[arr], 1);
    }
}