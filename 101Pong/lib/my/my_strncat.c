/*
** EPITECH PROJECT, 2020
** my_strncat.c by Elliot WALDVOGEL
** File description:
** my_strncat
*/

#include "../../include/my.h"
#include <unistd.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int length = my_strlen(dest);
    int over = 0;

    if (length >= nb) {
        for (int i = 0; i <= nb; i++) {
            dest[i] = dest[i];
            over = i;
        }
        dest[over] = '\0';
        return (dest);
    }
    for (int i = 0; (src[i] != '\0') && ((length + i) < nb); i++) {
        dest[length+i] = src[i];
        over = i;
    }
    dest[length+over+1] = '\0';
    return (dest);
}