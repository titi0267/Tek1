/*
** EPITECH PROJECT, 2020
** Flags & Main Function by Timothy CONIEL
** File description:
** my_printf.c
*/
#include "myp.h"

void my_vprintf(char *str, str_len_t *info, va_list *argu_list)
{
    void (*functionName[12]) (va_list *, str_len_t *) = {print_bin, print_char,
        print_nbr, print_nbr, print_unsigned, print_str,
        disp_oct, disp_hex, disp_hexa, store_len, print_ad, disp_nascii};
    char flag_board[13] = {'b', 'c', 'd', 'i', 'u', 's', 'o', 'x',
        'X', 'n', 'p', 'S', 0};
    int flag_nbr = 0;

    for (int arr = 0; str[arr] != 0; arr ++) {
        if (arr != 0 && str[arr - 2] != '%' && str[arr - 1] == '%'
            && str[arr] != '%') {
            flag_nbr = find_flag(flag_board, str[arr]);
            if (flag_nbr != -1)
                (*functionName[flag_nbr]) (argu_list, info);
        } else if (str[arr] != '%')
            my_putcharp(str[arr], info);
        if (str[arr - 1] == '%' && str[arr] == '%')
            my_putcharp('%', info);
    }
}

int my_printf(char *str, ...)
{
    int x = 0;
    str_len_t *info = malloc(sizeof(str_len_t));
    info->buf_size = 0;
    va_list argu_list;

    va_start(argu_list, str);
    my_vprintf(str, info, &argu_list);
    va_end(argu_list);
    x = info->buf_size;
    free(info);
    return (0);
}