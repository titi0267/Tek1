/*
** EPITECH PROJECT, 2021
** tools2
** File description:
** tools2.c
*/

#include "../../include/func_name.h"

int my_strlen(char *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}

static int nbr_len(int nb)
{
    int len = 0;

    for (int div = 1; nb != 0; div *= 10) {
        nb /= 10;
        len++;
    }
    return (len);
}

char *my_putnbr(int nb)
{
    int d = 1;
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (nbr_len(nb) + 2));
    if (nb < 0) {
        str[i] = '-';
        i++;
        nb *= -1;
    }
    for (; (nb / d) >= 10; d *= 10);
    for (; d > 0; d /= 10) {
        str[i] = ((nb / d) % 10 + '0');
        i++;
    }
    str[i] = '\0';
    return (str);
}

int compare_equal_colors(sfColor c1, sfColor c2)
{
    if (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)
        return (COLLISION);
    return (0);
}