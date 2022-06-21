/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-sylvian.burn
** File description:
** my_printf2.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

void my_put_nbr(int nb)
{
    int d = 1;

    if (nb == -2147483648) {
        write(2, "-2147483648", 13);
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        while ((nb / d) >= 10) {
            d *= 10;
        }
        while (d > 0) {
            my_putchar((nb / d) % 10 + '0');
            d /= 10;
        }
    }
}

void my_put_unsnbr(unsigned int nb)
{
    unsigned int d = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / d) >= 10) {
        d *= 10;
    } while (d > 0) {
        my_putchar((nb / d) % 10 + '0');
        d /= 10;
    }
}

void my_print_unsigned_nbr(va_list *to_print)
{
    unsigned int nb = va_arg(*to_print, unsigned int);
    unsigned int d = 1;

    if (nb == -4294967295) {
        write(2, "-4294967295", 13);
    } else {
        if (nb < 0) {
            my_put_unsnbr(4294967295 - (nb + 1));
        }
        while ((nb / d) >= 10) {
            d *= 10;
        } while (d > 0) {
            my_putchar((nb / d) % 10 + '0');
            d /= 10;
        }
    }
}

void my_print_char(va_list *to_print)
{
    char c = va_arg(*to_print, int);

    my_putchar(c);
}