/*
** EPITECH PROJECT, 2020
** display binary by Timothy CONIEL
** File description:
** disp_bin.c
*/
#include "myp.h"

void print_bin(va_list *argu_list, str_len_t *info)
{
    unsigned int i = va_arg(*argu_list, unsigned int);

    if (i <= 0)
        i = my_put_uint(i, info);
    convert_base(i, 2, info);
}
