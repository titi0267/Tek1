/*
** EPITECH PROJECT, 2021
** lib.c
** File description:
** lib.c
*/

#include <unistd.h>
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_getnbr(char *str)
{
    int i = 0;
    int j = 0;
    int n = 1;

    for (; str[i] != '\0' && (str[i] == '+' || str[i] == '-'); i++) {
        if (str[i] == '-')
            n *= -1;
    }
    for (; str[i] != '\0' && str[i] <= '9' && str[i] >= '0'; i++)
        j = j * 10 + str[i] - 48;
    if (n == -1)
        return ((-1) * j);
    else
        return (j);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i+= 1;
    }
    return (i);
}

int my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) -1;
    char temp;

    while (i <= len) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
    return (i);
}
