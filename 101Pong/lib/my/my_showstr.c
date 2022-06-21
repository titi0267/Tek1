/*
** EPITECH PROJECT, 2020
** my_showstr.c by Elliot WALDVOGEL
** File description:
** my_showstr
*/

#include "../../include/my.h"

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            if (str[i] < 14)
                my_putchar('0');
            my_putnbr_base((str[i]), "0123456789abcdef");
        }
        else
            my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}