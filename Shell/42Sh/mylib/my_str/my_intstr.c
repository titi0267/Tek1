/*
** EPITECH PROJECT, 2020
** my_intstr
** File description:
** convert an int to a string
*/

#include <stdlib.h>
#include "my.h"

static unsigned char is_neg(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        return 1;
    }
    return 0;
}

static unsigned int get_number_length(long nb)
{
    int length = 1;

    while (nb / length > 9) {
        length *= 10;
    }
    return length;
}

char *my_intstr(int nb)
{
    long l_nb = nb;
    int digit;
    unsigned int length;
    char *str;
    int i = 0;

    if (is_neg(l_nb))
        l_nb *= -1;
    length = get_number_length(l_nb);
    str = malloc(sizeof(char) * (length + 1));
    while (length > 0) {
        digit = l_nb / length;
        str[i] = 48 + digit;
        l_nb = l_nb - l_nb / length * length;
        length /= 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}