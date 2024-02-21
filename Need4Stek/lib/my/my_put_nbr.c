/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** my_putnbr
*/

#include "../../include/my.h"

int my_put_nbr(int nb, infin_number_t *info)
{
    int check = 0;

    if (nb < 0) {
        if (nb == -2147483648) {
            check = 1;
            nb /= 10;
        }
        nb *= -1;
        my_putchar('-', info);
    }
    if (nb >= 10) {
        my_put_nbr(nb/10, info);
    }
    my_putchar(nb%10+48, info);

    if (check == 1)
        my_putchar('8', info);
    return (0);
}