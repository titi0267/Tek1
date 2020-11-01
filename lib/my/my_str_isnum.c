/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_str_isnum.c
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