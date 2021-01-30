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
        if (str[i] != ' ' && nbr == 0)
            nbr += 1;
        if (str[i] == ' ' && str[i + 1] != ' ' && i != 0 && nbr != 0)
            nbr++;
    }
    return (nbr);
}

int my_error(char *str)
{
    write(2, str, my_strlen(str));
    return (84);
}