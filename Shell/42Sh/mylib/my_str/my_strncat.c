/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** appends n characters of a string to the end of another
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_length = my_strlen(dest) - 1;
    int i = 0;

    while (i < nb) {
        dest[dest_length + i] = src[i];
        i++;
    }
    dest[dest_length + i] = '\0';
    return (dest);
}
