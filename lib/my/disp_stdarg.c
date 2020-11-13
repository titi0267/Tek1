/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-bsmyprintf-timothe.coniel
** File description:
** disp_stdarg
*/
#include "my.h"
#include "my_struct.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void my_vprintf(char *str, str_len_t *info, va_list *argu_list)
{
    void (*functionName[11]) (va_list *, str_len_t *) = {print_bin, print_char, print_nbr, print_nbr, print_percent, print_unsigned, print_str, disp_oct, disp_hex, disp_hex, store_len};
    char flag_board[12] = {'b', 'c', 'd', 'i', '%', 'u', 's', 'o', 'x', 'X', 'n',0};
    int flag_nbr = 0;

    for (int arr = 0; str[arr] != 0; arr ++) {
        if (arr != 0 && str[arr - 1] == '%' && str[arr] != ' ') {
            flag_nbr = find_flag(flag_board, str[arr]);
            if (flag_nbr != -1) {
                (*functionName[flag_nbr]) (argu_list, info);
            }
        } else if (str[arr] != '%') {
            my_putchar(str[arr], info);
        }
    }
}

int my_printf(char *str, ...)
{
    str_len_t *info = malloc(sizeof(str_len_t));
    info->buf_size = 0;
    va_list argu_list;

    va_start(argu_list, str);
    my_vprintf(str, info, &argu_list);
    va_end(argu_list);
    return (info->buf_size);
}