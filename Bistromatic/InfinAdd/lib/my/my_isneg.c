/*
** EPITECH PROJECT, 2020
** my_inseg
** File description:
** 
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
}
