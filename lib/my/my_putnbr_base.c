/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** my_putnbr_base
*/
#include "my.h"

int convert_bin(unsigned int nb, int base)
{
    int x = 100;
    int r = 0;
    int a[x];

    a[x] = malloc(sizeof(int) * 100);
    while (nb > 0 && base != 16) {
        a[r] = (nb % base);
        nb /= base;
        r ++;
    }
    for (int j = r - 1; j >= 0 && base != 16; j --)
        my_put_nbr(a[j]);
}

int convert_minus(int nb)
{
    if (nb <= 0) {
        if (nb == 0)
            my_putchar('0');
        if (nb < 0) {
            nb = nb *= -1;
            my_putchar('-');
        }
    }
    return (nb);
}

int convert_oct(int nb, int base)
{
    int x = 100;
    int r = 0;
    int a[x];

    a[x] = malloc(sizeof(int) * 100);
    nb = convert_minus(nb);
    while (nb > 0 && base != 16) {
        a[r] = (nb % base);
        nb /= base;
        r ++;
    }
    for (int j = r - 1; j >= 0 && base != 16; j --)
        my_put_nbr(a[j]);
}

int convert_hex(int nb)
{
    int x = 100;
    int r = 0;
    int f = 0;
    int a[x];
    char hex[x];
    int i = 0;

    a[x] = malloc(sizeof(int) * 100);
    hex[x] = malloc(sizeof(char) * 100);
    nb = convert_minus(nb);
    while (nb != 0) {
        a[r] = nb % 16;
        if (a[r] < 10)
            hex[f++] = 48 + a[r];
        else
            hex[f++] = 55 + a[r];
        nb = nb / 16;
    }
    for (i = f; i >= 0; i--)
            my_putchar(hex[i]);
    return 0;
}