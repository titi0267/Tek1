/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-rush2-theo.grandvillain
** File description:
** my_putnbr.c
*/

#include "../../include/my.h"

void my_put_nbr(int nb)
{
    int d = 1;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        while ((nb / d) >= 10) {
            d *= 10;
        } while (d > 0) {
            my_putchar((nb / d) % 10 + '0');
            d /= 10;
        }
    }
}