/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** 
*/
#include "my.h"

 char *my_strcat(char *dest, char const *src)
 {
    int i = 0;
    int j;

    j = my_strlen(dest);
    for (i = 0; src[j] != '\0'; j += 1) {
        dest[i] = src[j];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
 }
