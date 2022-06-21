/*
** EPITECH PROJECT, 2020
** my_strcmp_non_constant.c by Elliot WALDVOGEL
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int compare_s1nc(char *s1, char *s2)
{
    int count = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[i])
            count += 0;
        else if (s1[i] > s2[i])
            count += 1;
        else
            count -= 1;
    }
    return (count);
}

int compare_s2nc(char *s1, char *s2)
{
    int count = 0;

    for (int i = 0; s2[i] != '\0'; i++) {
        if (s1[i] == s2[i])
            count += 0;
        else if (s1[i] > s2[i])
            count += 1;
        else
            count -= 1;
    }
    return (count);
}

int my_strcmp_non_constant(char *s1, char *s2)
{
    int count1 = 0;
    int length1 = my_strlen_non_constant(s1);
    int length2 = my_strlen_non_constant(s2);

    if (length1 > length2)
        return (compare_s1(s1, s2));
    else if (length1 < length2)
        return (compare_s2(s1, s2));
    else
        return (compare_s1(s1, s2));
}