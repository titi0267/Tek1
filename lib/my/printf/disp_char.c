/*
** EPITECH PROJECT, 2020
** Display character by Timothy CONIEL
** File description:
** disp_char.c
*/
#include "myp.h"

void print_char(va_list *argu_list, str_len_t *info)
{
    char c = va_arg(*argu_list, int);

    my_putcharp(c, info);
}
