/*
** EPITECH PROJECT, 2020
** nbrline.c
** File description:
** 
*/

#include "../include/my.h"

int nbr_line(char *buffer)
{
    int i = 0;
    int y = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            y++;
        i++;
    }
    return (y);
}

int char_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        i++;
    }
    return (i + 1);
}

void rm_question_mark(stumper_t *stp)
{
    for (int i = 0; stp->star[i] != '\0'; i++) {
        if (stp->star[i] != '*' && i != 0)
            stp->star[i] = '*';
    }
}
