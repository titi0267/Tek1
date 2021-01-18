/*
** EPITECH PROJECT, 2020
** my_put_unsigned_int by Timothy CONIEL
** File description:
** my_putuint.c
*/
#include "myp.h"

unsigned int my_put_uint(int nb, str_len_t *info)
{
    unsigned int d = 1;
    unsigned int i = 4294967295;

    if (nb < 0) {
        i = i - nb;
        return (i);
    }
    while ((nb / d) >= 10)
        d *= 10;
    while (d > 0) {
        my_putcharp((nb / d) % 10 + 48, info);
        d /= 10;
    }
    return (0);
}
