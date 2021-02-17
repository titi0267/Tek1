/*
** EPITECH PROJECT, 2020
** Display Number by Timothy CONIEL
** File description:
** disp_nbr.c
*/
#include "myp.h"

void print_nbr(va_list *argu_list, str_len_t *info)
{
    int x = va_arg(*argu_list, int);

    my_putnbrp(x, info);
}
