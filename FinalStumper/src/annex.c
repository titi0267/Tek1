/*
** EPITECH PROJECT, 2020
** annex.c for rush3.c by Elliot WALDVOGEL
** File description:
** annex
*/

#include "../include/my.h"
#include "../include/my_struct.h"

void detectFirstChar(char c, infin_number_t *info)
{
    if (c == 'o' || c == '-' || c == '|')
        info->first = info->first + 1;
    if (c == '/' || c == '*')
        info->second = info->second + 1;
    if (c == 'A' || c == 'B') {
        info->third = info->third + 1;
        info->fourth = info->fourth + 1;
        info->fifth = info->fifth + 1;
    }
}

void detectSecondChar(char c, infin_number_t *info)
{
    if (c == 'o' || c == '-' || c == '|')
        info->first = info->first + 1;
    if (c == '\\' || c == '*')
        info->second = info->second + 1;
    if (c == 'A' || c == 'B')
        info->third = info->third + 1;
    if (c == 'C' || c == 'B') {
        info->fourth = info->fourth + 1;
        info->fifth = info->fifth + 1;
    }
}

void detectLastChar(char c, infin_number_t *info)
{
    if (c == 'o' || c == '-' || c == '|')
        info->first = info->first + 1;
    if (c == '/' || c == '*')
        info->second = info->second + 1;
    if (c == 'C' || c == 'B') {
        info->fourth = info->fourth + 1;
        info->third = info->third + 1;
    }
    if (c == 'A' || c == 'B')
        info->fifth = info->fifth + 1;
}

int determine(char *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        a += str[i] - 48;
        if (str [i + 1] != '\0')
            a *= 10;
    }
    return (a);
}