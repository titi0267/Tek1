/*
** EPITECH PROJECT, 2020
** Yo
** File description:
** Man
*/

#include "./include/my.h"

int check_str(char *str, char *pattern, int position)
{
    int j = position;
    for (int i = 0; i < my_strlen(pattern) && str[i] != '\0'; i++) {
        if (str[j++] == pattern[i]) {
            continue;
        } else {
            return (0);
        }
    }
    return (1);
}

char *my_strstr(char *str, char *to_find)
{
    int tests = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (*(str + i) == *to_find) {
            tests = check_str(str, to_find, i);
        }
        if (tests == 1) {
            return (str + i);
        }
    }
    if ((*to_find == '\0' && *str == '\0') || (*to_find == 0)) {
        return (str);
    } else if (my_strlen(str) < my_strlen(to_find)) {
        return (str);
    } else {
        return (0);
    }
}