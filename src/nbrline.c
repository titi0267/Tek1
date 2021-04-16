/*
** EPITECH PROJECT, 2021
** nbrline.c
** File description:
** nbrline.c
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

int nbr_char(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        i++;
    }
    return (i + 1);
}
