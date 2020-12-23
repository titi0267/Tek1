/*
** EPITECH PROJECT, 2020
** my_put_number by Timothy CONIEL
** File description:
** my_putnbr.c
*/

#include "my.h"

int my_putnbr(int nb)
{
    int d = 1;

    if (nb == -2147483648)
        my_putstr("-2147483648");
    else {
        if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
        for (; (nb / d) >= 10; d *= 10);
        for (; d > 0; d /= 10)
            my_putchar((nb / d) % 10 + '0');
    }
}
