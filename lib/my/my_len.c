/*
** EPITECH PROJECT, 2021
** my_strlen by Timothy CONIEL
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return (len);
}

int my_wordnbr(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            nbr++;
    }
    nbr += 1;
    return (nbr);
}
