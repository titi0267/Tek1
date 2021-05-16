/*
** EPITECH PROJECT, 2021
** B-AIA-200-STG-2-1-n4s-elliot.waldvogel
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

char **malloc_double(char *str, int space)
{
    char **my_tab;
    int p = 0;

    my_tab = malloc(sizeof(char *) * (space + 2));
    for (; p < space; p++)
        my_tab[p] = malloc(sizeof(char) * (my_strlen(str) + 2));
    my_tab[p] = NULL;
    return (my_tab);
}

void compare_clear(char *str, nfors_t *nfs, int tab_len)
{
    char *string = malloc(sizeof(char) * 15);
    int count = 0;
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'T' && str[i + 1] == 'r' && str[i + 2] == 'a')
            count = 1;
        if (count == 1) {
            string[x] = str[i];
            x++;
        }
    }
    if (my_strcmp(string, "Track Cleared") == 0)
        nfs->end_car = 1;
    free(string);
}

void my_str_to_word_array(char *str, nfors_t *nfs)
{
    nfs->tab_len = 1;
    int x = 0;
    int y = 0;

    for (int z = 0; str[z]; z++)
        if (str[z] == ':')
            nfs->tab_len++;
    compare_clear(str, nfs, nfs->tab_len);
    if (nfs->tab_len > 15) {
        nfs->my_tab = malloc_double(str, nfs->tab_len);
        for (int i = 0; x <= (nfs->tab_len - 1); x++) {
            for (; str[i] != ':' && str[i] != '\n'; i++, y++)
                nfs->my_tab[x][y] = str[i];
            nfs->my_tab[x][y] = '\0';
            i++;
            y = 0;
        }
    }
}
