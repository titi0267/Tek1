/*
** EPITECH PROJECT, 2020
** annex1.c by Elliot WALDVOGEL
** File description:
** annex1
*/

#include "../../include/my.h"
#include <stdarg.h>

void pchar(va_list *my_list, infin_number_t *info)
{
    char c = va_arg(*my_list, int);

    my_putchar(c, info);
}

void pint(va_list *my_list, infin_number_t *info)
{
    int i = va_arg(*my_list, int);

    my_put_nbr(i, info);
}

void pstr(va_list *my_list, infin_number_t *info)
{
    char *str = va_arg(*my_list, char *);

    my_putstr(str, info);
}

void poct(va_list *my_list, infin_number_t *info)
{
    int i = va_arg(*my_list, int);

    my_putnbr_base(i, "01234567", info);
}

void phex(va_list *my_list, infin_number_t *info)
{
    int i = va_arg(*my_list, int);

    my_putnbr_base(i, "0123456789ABCDEF", info);
}