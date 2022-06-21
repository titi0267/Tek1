/*
** EPITECH PROJECT, 2020
** my_put_number_printf by Timothy CONIEL
** File description:
** my_putnbrp.c
*/
#include "myp.h"

int my_putnbrp(int nb, str_len_t *info)
{
    int d = 1;

    if (nb == -2147483648)
        my_putstrp("-2147483648", info);
    else {
        if (nb < 0) {
            my_putcharp('-', info);
            nb *= -1;
        }
        while ((nb / d) >= 10)
            d *= 10;
        while (d > 0) {
            my_putcharp((nb / d) % 10 + '0', info);
            d /= 10;
        }
    }
    return (0);
}
