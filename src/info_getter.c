/*
** EPITECH PROJECT, 2021
** info_getter.c for n4s project by Maxime HOFFBECK, Timothy CONIEL & Elliot WALDVOGEL
** File description:
** info_getter
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void order_line(void)
{
    size_t len = 4096;
    char *str = NULL;

    getline(&str, &len, stdin);
    my_str_to_word_array(str);
}

void coordinates(void)
{
    size_t buffsize = 4096;
    char *str = malloc(buffsize * sizeof(char));
    static int first = 0;

    getline(&str, &buffsize, stdin);
    if (first >= 1)
        my_str_to_word_array(str);
    first++;
    //dprintf(2, "LA SORTIE = %s\n", str);
    //my_puterr(str);
}