/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int length = my_strlen(src);

    if (n > length) {
        while (src[i] != '\0' && i < n) {
            dest[i] = src[i];
            i += 1;
        }
        dest[i] = '\0';
        return (dest);
    }
    else {
        while (src[i] != '\0' && i < n) {
            dest[i] = src[i];
            i += 1;
        }
        return (dest);
    }
}