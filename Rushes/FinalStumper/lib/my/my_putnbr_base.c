/*
** EPITECH PROJECT, 2020
<<<<<<< HEAD
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
=======
** my_putnbr_base.c by Elliot WALDVOGEL
** File description:
** my_putnbr_base
*/

void my_putchar_pnbr(char c)
{
    write(1, &c, 1);
}

int my_strlen_pnbr(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return (count);
}

int my_putnbr_base(int nbr, char const *base)
{
    int length = my_strlen_pnbr(base);
    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar_pnbr('-');
    }
    if (nbr == 0)
        return (0);
    else
        my_putnbr_base(nbr/length, base);
    my_putchar_pnbr(base[nbr%length]);
    return (0);
}
>>>>>>> FinalStumper
