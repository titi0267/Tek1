/*
** EPITECH PROJECT, 2021
** my_strlen by Timothy CONIEL
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return (len);
}