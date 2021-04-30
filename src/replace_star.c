/*
** EPITECH PROJECT, 2021
** replace_star.c
** File description:
** replace_star
*/

#include "../include/my.h"

int replace_star(stumper_t *stp)
{
    int i = 0;

    while (stp->line[stp->word][i] != '\0') {
        printf("*");
        i++;
    }
}
