/*
** EPITECH PROJECT, 2020
** Display Hexadecimal by Timohty CONIEL
** File description:
** disp_hex.c
*/
#include "myp.h"

void disp_heX(va_list *argu_list, str_len_t *info)
{
    unsigned int e = va_arg(*argu_list, unsigned int);

    convert_heX(e, info);
}

void disp_hex(va_list *argu_list, str_len_t *info)
{
    unsigned int e = va_arg(*argu_list, unsigned int);

    convert_hex(e, info);
}
