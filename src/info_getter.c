/*
** EPITECH PROJECT, 2021
** info_getter.c for n4s project by Maxime HOFFBECK, Timothy CONIEL & Elliot WALDVOGEL
** File description:
** info_getter
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void coordinates(char *str, size_t size_t)
{
    getline(&str, &size_t, stdout);
    my_puterr(str);
}