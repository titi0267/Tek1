/*
** EPITECH PROJECT, 2020
** mylib
** File description:
** my_strmerge
*/

#include <stdlib.h>
#include "my.h"

char *my_strmerge(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *str = malloc(sizeof(char) * (len1 + len2 + 1));

    if (str == NULL)
        return (NULL);
    my_strcpy(str, str1);
    my_strcat(str, str2);
    return (str);
}