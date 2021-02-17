/*
** EPITECH PROJECT, 2021
** my line counter by Timothy CONIEL
** File description:
** my_line_counter.c
*/

#include "my.h"

int count_line(char *str)
{
    int y = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            y++;
    }
    if (str[i - 1] != '\n')
        y += 1;
    return (y);
}