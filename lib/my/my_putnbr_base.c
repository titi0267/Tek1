/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** my_putnbr_base
*/
#include "my.h"

int convert_base(unsigned int nb, int base)
{
    int a[100];
    int r = 0;

    while (nb > 0) {
        a[r] = (nb % base);
        nb /= base;
        r ++;
    }
    for (int j = r - 1; j >= 0; j --)
        my_put_nbr(a[j]);
}