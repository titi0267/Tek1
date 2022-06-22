/*
** EPITECH PROJECT, 2020
** Display Octal by Timothy CONIEL
** File description:
** disp_oct.c
*/
#include "myp.h"

void disp_oct(va_list *argu_list, str_len_t *info)
{
    unsigned int i = va_arg(*argu_list, unsigned int);

    convert_base(i, 8, info);
}
