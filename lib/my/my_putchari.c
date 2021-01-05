/*
** EPITECH PROJECT, 2020
** my_putchari.c by Elliot WALDVOGEL
** File description:
** my_putchari
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my_struct.h"

int my_putchari(char c)
{
    if (c < 32 && c > 126)
        return (-1);
    else {
        write(1, &c, 1);
    }
}