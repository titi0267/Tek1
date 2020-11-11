/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** my_put_uint
*/

#include "my.h"

unsigned int my_put_uint(unsigned int nb)
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
        my_putchar((nb / d) % 10 + 48);
        d /= 10;
    }
}