/*
** EPITECH PROJECT, 2020
** Display Unsigned Int by Timothy CONIEL
** File description:
** disp_uint.c
*/
#include "myp.h"

void print_unsigned(va_list *argu_list, str_len_t *info)
{
    unsigned int u = va_arg(*argu_list, unsigned int);

    my_put_uint(u, info);
}
