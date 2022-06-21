/*
** EPITECH PROJECT, 2020
** my_put_string by Timothy  CONIEL
** File description:
** my_putstr.c
*/
#include "myp.h"

int my_putstrp(char const *str, str_len_t *info)
{
    for (int carac = 0; str[carac] != '\0'; carac++)
        my_putcharp(str[carac], info);
    return (0);
}
