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

void average_left(nfors_t *nfs)
{
    nfs->average_left = 0;

    //dprintf(2, "2 = %s & 3 = %s\n", nfs->my_tab[2], nfs->my_tab[3]);
    for (int i = 3; i <= 18; i++)
        nfs->average_left += atoi(nfs->my_tab[i]);
    nfs->average_left = nfs->average_left / 16;
}

void average_right(nfors_t *nfs)
{
    nfs->average_right = 0;

    //dprintf(2, "2 = %s & 3 = %s\n", nfs->my_tab[34], nfs->my_tab[35]);
    for (int i = 19; i <= 34; i++)
        nfs->average_right += atoi(nfs->my_tab[i]);
    nfs->average_right = nfs->average_right / 16;
}

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
    //stop_car(nfs);
    /*if (nfs->tab_len > 33) {
        average_left(nfs);
        average_right(nfs);
    }*/
}

/*void coordinates(void)
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
}*/