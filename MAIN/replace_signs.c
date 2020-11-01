/*
** EPITECH PROJECT, 2020
** bistromatic [WSL: Ubuntu]
** File description:
** replace_signs
*/
#include "../include/my.h"
#include <stdlib.h>

static char get_sign(int sign_num)
{
    char c;

    if (sign_num == 0)
        c = '(';
    if (sign_num == 1)
        c = ')';
    if (sign_num == 2)
        c = '+';
    if (sign_num == 3)
        c = '-';
    if (sign_num == 4)
        c = '*';
    if (sign_num == 5)
        c = '/';
    if (sign_num == 6)
        c = '%';
    return (c);
}

static void replace_sign(char cur, char *to_convert, int sign_num) 
{
    for (int i = 0; to_convert[i] != '\0'; i++) {
        if (to_convert[i] == cur)
            to_convert[i] = get_sign(sign_num);
    }
}

void replace_signs(char *av2, char *to_convert)
{
    for (int i = 0; av2[i] != '\0'; i++)
        replace_sign(av2[i], to_convert, i);

}