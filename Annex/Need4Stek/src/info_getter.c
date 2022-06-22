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

void order_line(nfors_t *nfs)
{
    size_t len = 4096;
    char *str = NULL;

    getline(&str, &len, stdin);
    if (nfs->end_car == 0)
        my_str_to_word_array(str, nfs);
}
