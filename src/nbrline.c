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
        i++;
        if (buffer[i] == '\n')
            y++;
    }
    return (y);
}

int nbr_char(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        i++;
    }
    return (0);
}
