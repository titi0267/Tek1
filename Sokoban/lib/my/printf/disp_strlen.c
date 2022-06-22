/*
** EPITECH PROJECT, 2020
** Display String Length by Timothy CONIEL$
** File description:
** disp_strlen.c
*/
#include "myp.h"

void store_len(va_list *argu_list, str_len_t *info)
{
    int v = info->buf_size;

    my_putnbrp(v, info);
}
