/*
** EPITECH PROJECT, 2020
** yo
** File description:
** yomecs
*/

#include "./include/my.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    int mem = my_strlen(str) + 1;
    char *to_return = malloc(sizeof(char) * mem);
    my_strcpy(to_return, str);
    return (to_return);
}
