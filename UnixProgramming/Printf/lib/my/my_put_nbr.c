/*
** EPITECH PROJECT, 2020
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
