/*
** EPITECH PROJECT, 2020
** annex2.c for my_printf.c by Elliot WALDVOGEL
** File description:
** annex2
*/

#include "../../include/my.h"
#include <stdarg.h>

void phun(va_list *my_list, infin_number_t *info)
{
    int i = va_arg(*my_list, int);

    my_put_nbr_u(i, info);
}

void pbin(va_list *my_list, infin_number_t *info)
{
    int i = va_arg(*my_list, int);
    unsigned int nb = 0;
    int nb1 = 0;
    int nb2 = 0;

    if (i < 0) {
        nb = 4294967296 + i;
        my_putnbr_base_u(nb, "01", info);
    }
    else
        my_putnbr_base_u(i, "01", info);
}

void pn(va_list *my_list, infin_number_t *info)
{
    int i = va_arg(*my_list, int);
    int a = info->amount;

    my_put_nbr(a, info);
}

void perc(va_list *my_list, infin_number_t *info)
{
    my_putchar('%', info);
}

void pp(va_list *my_list, infin_number_t *info)
{
    long long int i = va_arg(*my_list, int);

    my_putstr("0x7ff", info);
    my_putnbr_base_u(i, "0123456789abcdef", info);
}