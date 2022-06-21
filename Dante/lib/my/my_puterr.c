/*
** EPITECH PROJECT, 2021
** my put error
** File description:
** my_puterr.c
*/

#include "../../include/my.h"

int my_puterr(char *str)
{
    write(2, str, my_strlen(str));
    return (84);
}