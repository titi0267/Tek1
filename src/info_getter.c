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

// WHEELS_DIR:float

void stop_car(nfors_t *nfs)
{
    // static int end = 0;

    // if (my_strcmp(nfs->my_tab[3], "Track Cleared") == 0) {
    //     end = 1;
    // }
    if (nfs->tab_len < 21)
        return;
    if (atoi(nfs->my_tab[20]) < 450)
        nfs->stop = 1;
    return;
}

void order_line(nfors_t *nfs)
{
    size_t len = 4096;
    char *str = NULL;

    getline(&str, &len, stdin);
    my_str_to_word_array(str, nfs);
}
