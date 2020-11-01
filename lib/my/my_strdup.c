/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strdup.c
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
