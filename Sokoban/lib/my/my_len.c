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

int word_tablen(char **str)
{
    int i = 0;
    int count = 0;
    int y = 0;

    for (; str[i] != 0; i++) {
        for (; str[i][y] != '\0'; y++);
        count++;
        y = 0;
    }
    return (count);
}

int my_tabint(int *nbr)
{
    int i = 0;

    for (; nbr[i] != -1; i++);
    return (i);
}

int find_char(char *str, char ascii, int i)
{
    int count = 0;

    if (i == 0) {
        for (int c = 0; str[c] != '\0'; c++) {
            if (str[c] == ascii)
                count++;
        }
        return (count);
    }
    if (i == 1) {
        for (int f = 0; str[f] != '\0'; f++) {
            if (str[f] == ascii)
                return (1);
        }
    }
    return (0);
}