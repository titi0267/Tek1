/*
** EPITECH PROJECT, 2020
** PRINTF
** File description:
** disp_char
*/
#include "../include/my.h"
#include <stdarg.h>

void print_char(va_list *argu_list)
{
    char c = va_arg(*argu_list, int);

    my_putchar(c);
}