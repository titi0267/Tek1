/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** allocate memory and copy content of a given string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int str_length = my_strlen(src);
    char *str = malloc(sizeof(char) * (str_length + 1));

    my_strcpy(str, src);
    return (str);
}