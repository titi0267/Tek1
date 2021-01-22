/*
** EPITECH PROJECT, 2021
** frequency by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** frequency.c
*/

#include "../include/my.h"
#include <stdio.h>

int letter_freq(ant_t *ant)
{
    int c = 0;
    int x = 0;
    float d = 0;

    ant->l_freq = malloc(sizeof(int) * ant->diff_let);
    if (ant->l_freq == NULL)
        return (-1);
    for (; ant->line[c] != 0; c++) {
        for (; ant->line[c][x] != '\0'; x++) {
            my_printf("%c", ant->line[c][x]);
        }
        d = x;
        //d = 9/3;
        ant->l_freq[c] = d / ant->diff_let;
        my_printf("x = %i & diff = %i\n", x, ant->diff_let);
        printf("%f\n", ant->l_freq[c]);
        x = 0;
    }
    return (0);
}