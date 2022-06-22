/*
** EPITECH PROJECT, 2020
** my_strcat.c by Elliot WALDVOGEL
** File description:
** my_strcat
*/

#include "../../include/my.h"
#include <unistd.h>

char *my_strcat(char *dest, char const *src)
{
    int length = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[length] = src[i];
        length++;
    }
    dest[length+1] = '\0';
    return (dest);
}