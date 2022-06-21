/*
** EPITECH PROJECT, 2021
** my strlen by Timothy CONIEL
** File description:
** my_strlen.c
*/

#include "my.h"

int my_strlen(char *str)
{
    int count = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        count++;
    }
    return (count);
}