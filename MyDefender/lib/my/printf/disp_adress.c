/*
** EPITECH PROJECT, 2020
** display adress by Timothy CONIEL
** File description:
** disp_adress.c
*/
#include "myp.h"

void print_ad(va_list *argu_list, str_len_t *info)
{
    void *x = va_arg(*argu_list, void *);
    uintptr_t y = (uintptr_t)x;

    my_putstrp("0x", info);
    convert_ad(y, info);
}
