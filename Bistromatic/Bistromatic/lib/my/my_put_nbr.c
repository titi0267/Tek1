/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_put_nbr.c
*/

#include "./include/my.h"

int check_if_p(int l)
{
    if (l >= 0)
        return (1);
    else
        return (0);
}

int lengthsp(int num)
{
    int numt = num;
    int i;

    if (numt == 0)
        return (1);
    for (i = 1; numt != 0; i++)
        numt = numt / 10;
    return (i - 1);
}

int pow_ten(int amout)
{
    int tenden = 1;

    for (int h = 0; h < amout; ++h)
        tenden = tenden * 10;
    return (tenden);
}

int my_put_nbr(int nb)
{
    int currents;

    if (!check_if_p(nb)) {
        my_putchar('-');
        nb = nb * -1;
    }
    for (int k = 1; k <= lengthsp(nb); k++) {
        currents = (nb / pow_ten(lengthsp(nb) - k)) % 10;
        my_putchar(currents + 48);
    }
}
