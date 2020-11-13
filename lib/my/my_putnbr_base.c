/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** my_putnbr_base
*/
#include "my.h"
#include "my_struct.h"
#include <stdlib.h>

int convert_bin(unsigned int nb, int base, str_len_t *info)
{
    int x = 100;
    int r = 0;
    int a[x];

    //a[x] = malloc(sizeof(int) * 100);
    while (nb > 0 && base != 16) {
        a[r] = (nb % base);
        nb /= base;
        r ++;
    }
    for (int j = r - 1; j >= 0 && base != 16; j --)
        my_put_nbr(a[j], info);
    return (0);
}

int convert_minus(int nb, str_len_t *info)
{
    if (nb <= 0) {
        if (nb == 0)
            my_putchar('0', info);
        if (nb < 0) {
            nb *= -1;
            my_putchar('-', info);
        }
    }
    return (nb);
}

int convert_oct(int nb, int base, str_len_t *info)
{
    int x = 100;
    int r = 0;
    int a[x];

    //a[x] = malloc(sizeof(int) * 100);
    nb = convert_minus(nb, info);
    while (nb > 0 && base != 16) {
        a[r] = (nb % base);
        nb /= base;
        r ++;
    }
    for (int j = r - 1; j >= 0 && base != 16; j --)
        my_put_nbr(a[j], info);
    return (0);
}

int convert_hex(int nb, str_len_t *info)
{
    //int x = 100;
    int temp = 0;
    int f = 0;
    int i = 1;
    //int *a;
    char hex[100];

    //a = malloc(sizeof(int *) * x);
    hex[i] = malloc(sizeof(char *) * i);
    nb = convert_minus(nb, info);
    while (nb != 0) {
        temp = nb % 16;
        if (temp < 10)
            temp += 48;
        else
            temp += 55;
        hex[i++] = temp;
        nb = nb / 16;
    }
    for (f = i - 1; f >= 0; f--) {
        my_putchar(hex[f], info);
    }
    return (0);
}