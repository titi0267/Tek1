/*
** EPITECH PROJECT, 2020
** PRINTF
** File description:
** disp_char
*/
#include "my.h"
#include "my_struct.h"
#include <stdarg.h>

void print_char(va_list *argu_list, str_len_t *info)
{
    char c = va_arg(*argu_list, int);

    my_putchar(c, info);
}
