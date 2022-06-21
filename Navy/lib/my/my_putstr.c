/*
** EPITECH PROJECT, 2020
** my_putstr.c by Elliot WALDVOGEL
** File description:
** my_putstr
*/

#include "../../include/my.h"
#include "../../include/my_struct.h"
#include <unistd.h>

int my_putstr(char const *str, infin_number_t *info)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i], info);
    return (0);
}