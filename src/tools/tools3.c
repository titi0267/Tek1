/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tools3
*/

#include "../../include/func_name.h"

int point_distcance(sfVector2f mouse, sfVector2f map)
{
    int distancenew = sqrt(((map.x - mouse.x) * (map.x - mouse.x) / 2) +
    (map.y - mouse.y) * (map.y - mouse.y));

    return (distancenew);
}

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