/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** my_putnbr_base
*/
#include "my.h"
#include "my_struct.h"
#include <stdlib.h>

void convert_base(unsigned int nb, int base, str_len_t *info)
{
    int x = 100;
    int r = 0;
    int a[x];

    while (nb > 0 && base != 16) {
        a[r] = (nb % base);
        nb /= base;
        r ++;
    }
    for (int j = r - 1; j >= 0 && base != 16; j --)
        my_put_nbr(a[j], info);
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

void convert_heX(unsigned int nb, str_len_t *info)
{
    int temp = 0;
    int f = 0;
    int i = 1;
    char *hex = malloc(sizeof(char *));

    while (nb != 0) {
        temp = nb % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
            i++;
        } else {
            hex[i] = temp + 55;
            i++;
        }
        nb = nb / 16;
    }
    for (f = i - 1; f > 0; f--) {
        my_putchar(hex[f], info);
    }
}

void convert_hex(unsigned int nb, str_len_t *info)
{
    int temp = 0;
    int f = 0;
    int i = 1;
    char *hex = malloc(sizeof(char *));

    while (nb != 0) {
        temp = nb % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
            i++;
        } else {
            hex[i] = temp + 87;
            i++;
        }
        nb = nb / 16;
    }
    for (f = i - 1; f > 0; f--) {
        my_putchar(hex[f], info);
    }
}

void convert_ad(uintmax_t nb, str_len_t *info)
{
    int temp = 0;
    int f = 0;
    int i = 1;
    char *hex = malloc(sizeof(char *));

    while (nb != 0) {
        temp = nb % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
            i++;
        } else {
            hex[i] = temp + 87;
            i++;
        }
        nb = nb / 16;
    }
    for (f = i - 1; f > 0; f--) {
        my_putchar(hex[f], info);
    }
}
