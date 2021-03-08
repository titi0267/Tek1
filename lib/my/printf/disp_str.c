/*
** EPITECH PROJECT, 2020
** Display String by Timothy CONIEL
** File description:
** disp_str.c
*/
#include "myp.h"

void print_str(va_list *argu_list, str_len_t *info)
{
    char *str = va_arg(*argu_list, char *);

    my_putstrp(str, info);
}
