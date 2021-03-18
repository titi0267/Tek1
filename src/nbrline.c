/*
** EPITECH PROJECT, 2020
** nbrline.c
** File description:
** 
*/

#include "../include/my.h"

int nbr_char(char *buffer)
{
    int i = 0;
    int y = 0;

    while (buffer[i] != '\n')
        i++;
    i++;
    while (buffer[i] != '\n') {
        y++;
        i++;
    }
    y++;
    return (y);
}

char *nbr_line(char *buffer)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 10);

    if (str == NULL)
        return (NULL);
    while (buffer[i] != '\n') {
        str[i] = buffer[i];
        i++;
    }
    str[i] = '\n';
    i++;
    str[i] = '\0';
    return (str);
}
