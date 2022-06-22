/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_putstr.c
*/

#include "include/my.h"

int my_putstr(char const *str)
{
    for (int k = 0; str[k] != '\0'; k++)
        my_putchar(str[k]);
}
