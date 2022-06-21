/*
** EPITECH PROJECT, 2020
** my_chargetnbr.c by Elliot WALDVOGEL
** File description:
** my_chargetnbr
*/

#include "../../include/my.h"

int my_chargetnbr(char c)
{
    int i = 0;
    int j = 0;
    int n = 1;

    for (int i = 0; i < 9; i++) {
        if ((c - '0') == i)
            return (i);
    }
}