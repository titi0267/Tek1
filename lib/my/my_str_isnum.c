/*
** EPITECH PROJECT, 2020
** hh
** File description:
** hh
*/
#include "./include/my.h"
int check_nums(char c)
{
    if ((c >= '0') && (c <= '9')) {
        return (1);
    }
    return (0);
}

int my_str_isnum(char const *str)
{
    for (int i = 0; i <my_strlen(str); i++) {
        if (!check_nums(str[i])) {
            return (0);
        }
    }
    return (1);
}