/*
** EPITECH PROJECT, 2020
** bistromatic [WSL: Ubuntu]
** File description:
** replace_signs
*/

#include "../include/my.h"
#include <stdlib.h>


static char get_sign(int sign_num){
    char c;
    switch (sign_num)
    {
    case 0:
        c = '(';
        break;
    case 1:
        c = ')';
        break;
    case 2:
        c = '+';
        break;
    case 3:
        c = '-';
        break;
    case 4:
        c = '*';
        break;
    case 5:
        c = '/';
        break;
    case 6:
        c = '%';
        break;
    default:
        break;
    }
    return (c);
}

static void replace_sign(char cur, char *to_convert, int sign_num) 
{
    for(int i = 0; to_convert[i] != '\0'; i++)
    {
        if(to_convert[i] == cur)
            to_convert[i] = get_sign(sign_num);
    }
}

void replace_signs(char *av2, char *to_convert)
{
    for(int i = 0; av2[i] != '\0'; i++)
        replace_sign(av2[i], to_convert, i);

}

