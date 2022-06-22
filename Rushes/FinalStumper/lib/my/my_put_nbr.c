/*
** EPITECH PROJECT, 2020
<<<<<<< HEAD
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** my_put_nbr
*/
#include "my.h"
#include "my_struct.h"

int my_put_nbr(int nb, str_len_t *info)
{
    int d = 1;

    if (nb == -2147483648)
        my_putstr("-2147483648", info);
    else {
        if (nb < 0) {
        my_putchar('-', info);
            nb *= -1;
        }
        while ((nb / d) >= 10)
            d *= 10;
        while (d > 0) {
	        my_putchar((nb / d) % 10 + '0', info);
	        d /= 10;
	    }
        }
    return (0);
}
=======
** my_put_nbr.c
** File description:
** my_putnbr
*/

int my_put_nbr(int nb)
{
    int check = 0;

    if (nb < 0) {
        if (nb == -2147483648) {
            check = 1;
            nb /= 10;
        }
        nb *= -1;
        my_putchar('-');
    }

    if (nb >= 10) {
        my_put_nbr(nb/10);
    }
    my_putchar(nb%10+48);

    if (check == 1)
        my_putchar('8');
    return (0);
}
>>>>>>> FinalStumper
