/*
** EPITECH PROJECT, 2020
** annex.c by Timothé CONIEL & Elliot WALDVOGEL
** File description:
** annex
*/

#include "../include/my_struct.h"
#include "../include/my.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void core101(infin_number_t *info)
{
    int c = 3;
    int a = 0;
    float f = 0;

    my_putstr("The Velocity vector of this ball is :\n");
    for (;c < 8 && a < 3; a ++, c ++) {
        if (c == 3 && a == 0) {
            f = info->given[c] - info->given[a];
            printf("(%.2f, ", f);
        }
        if (c == 4 && a == 1) {
            f = info->given[c] - info->given[a];
            printf("%.2f, ", f);
        }
        if (c == 5 && a == 2) {
            f = info->given[c] - info->given[a];
            printf("%.2f)\n", f);
        }
    }
}