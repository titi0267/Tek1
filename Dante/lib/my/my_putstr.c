/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Displays the content of the char
*/

#include "../../include/my.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}