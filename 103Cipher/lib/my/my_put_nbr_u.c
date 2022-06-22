/*
** EPITECH PROJECT, 2020
** my_put_nbr_u.c by Elliot WALDVOGEL
** File description:
** my_put_nbr_u
*/

#include "../../include/my.h"
#include "../../include/my_struct.h"

unsigned int my_put_nbr_u(unsigned int nb, infin_number_t *info)
{
    int check = 0;

    if (nb < 0) {
        nb = 4294967295 - nb;
    }
    if (nb >= 10) {
        my_put_nbr_u(nb/10, info);
    }
    my_putchar(nb%10+48, info);
    if (check == 1)
        my_putchar('8', info);
    return (0);
}