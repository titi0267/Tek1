/*
** EPITECH PROJECT, 2020
** my_strstr.c by Elliot WALDVOGEL
** File description:
** my_strstr
*/

#include "../../include/my.h"

char const *my_strstr(char *str, char const *to_find)
{
    int count = 0;

    if (to_find == "")
        return (str);
    for (int i = 0; to_find[i] != '\0'; i++) {
        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] == to_find[i]) {
                i++;
                if (count == my_strlen(to_find))
                    return (to_find);
                count++;
            }
        }
    }
    return (0);
}