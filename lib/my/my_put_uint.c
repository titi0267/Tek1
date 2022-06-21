/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** my_put_uint
*/

#include "my.h"

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
        my_putchar((nb / d) % 10 + 48, info);
        d /= 10;
    }
    return (0);
}