/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-sylvian.burn
** File description:
** my_printf3.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void find_percentage(char *src, int i)
{
    if (src[i - 1] == '%') {
        if (src[i] == '%' && src[i + 1] != 's' && src[i + 1] != 'S' &&
            src[i + 1] != 'c' && src[i + 1] != 'd' && src[i + 1] != 'i' &&
            src[i + 1] != 'b' && src[i + 1] != 'u' && src[i + 1] != 'p' &&
            src[i + 1] != 'X' && src[i + 1] != 'x' && src[i + 1] != 'o') {
                my_putstr("%");
        }
    }
}

void my_print_str(va_list *to_print)
{
    char *str = va_arg(*to_print, char *);

    my_putstr(str);
}

void my_print_nbr(va_list *to_print)
{
    int nb = va_arg(*to_print, int);

    my_put_nbr(nb);
}