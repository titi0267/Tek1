/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tools3
*/

#include "../../include/func_name.h"

int my_getnbr(char const *str)
{
    int i = 0;
    long nbr = 0;
    int sign = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign *= -1;
        }
        i += 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr * 10 + str[i] - 48;
        i += 1;
    }
    nbr *= sign;
    if (nbr < -2147483648 || nbr > 2147483647)
        return (0);
    return ((int)nbr);
}

sfVector2i put_in_vector2i(int x, int y)
{
    sfVector2i pos = {x, y};

    return (pos);
}

float vol_checker(float x)
{
    float volume = (x - 1452.393) * 100 / 225.902;

    if (volume < 0)
        volume = 0;
    if (volume > 100)
        volume = 100;
    return (volume);
}

sfVector2f vect_x_y(sfVector2f vect, int add_x, int add_y)
{
    vect.x += add_x;
    vect.y += add_y;
    return (vect);
}