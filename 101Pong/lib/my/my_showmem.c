/*
** EPITECH PROJECT, 2020
** my_showmem.c by Elliot WALDVOGEL
** File description:
** my_showmem
*/

#include "../../include/stdio.h"
#include "../../include/my.h"
#include <unistd.h>

void display_line(char const *str, int size)
{
    my_putnbr_base(my_getnbr(str), "0123456789ABCDEF");
    my_putstr(": ");
    for (int i = 0; i < size; i++) {
        if(str[i] < 16)
            my_putchar('0');
        my_putnbr_base(my_chargetnbr(str[i]), "0123456789ABCDEF");
        if(i % 2 == 1)
            my_putchar(' ');
    }
    for (int i = 0; i < size; i++) {
        if (my_str_isprintable(str) == 1)
            my_putchar(str[i]);	
        else
            my_putchar('.');
    }
    my_putchar('\n');
}

int my_showmem(char const *str, int size)
{
    int i = 0;

    while (i < size) {
        display_line(str, 16);
        str = str + 16;
        i = i + 1;
    }
    return (0);
}