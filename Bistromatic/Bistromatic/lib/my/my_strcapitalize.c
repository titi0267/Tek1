/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strcapitalize.c
*/

#include "./include/my.h"

int chkl(char c)
{
    if (c > 96 && c < 123) {
        return (1);
    } else if (c > 64 && c < 91) {
        return (2);
    } else {
        return (0);
    }
}

static int after_smth(char c)
{
    if (((c >= '0') && (c <= '9')) || chkl(c) != 0) {
        return (0);
    } else if (c != '\0') {
        return (1);
    }
    return (0);
}

int cap(char *str)
{
    char *mem = str;

    if (chkl(*str) == 1) {
        *str = *str - 32;
    }
    str++;

    while (!after_smth(*str) && *str != '\0') {
        if (chkl(*str) == 2) {
            *str = *str + 32;
        }
        str++;
    }
    return (str - mem - 1);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((after_smth(str[i]) && chkl(str[i + 1]) != 0)) {
            i += cap(str + i + 1);
        } else if (str[i] >= '0' && str[i] <= '9') {
            i += cap(str + i);
        } else if (i == 0)
            i += cap(str + i);
    }
    return (str);
}