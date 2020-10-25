/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-evalexpr-sylvian.burn
** File description:
** summands
*/
#include "include/my.h"

int find_plus(char **str_ptr)
{
    int i = 0;
    int x = 0;

    for (; str_ptr[1][i] != '\0'; i += 1) {
        if (str_ptr[1][i] == '+')
            x = 1;
        if (str_ptr[1][i] == '*')
            x = 2;
        if (str_ptr[1][i] == '/')
            x = 3;
        if (str_ptr[1][i] == '-')
            x = 4;
        if (str_ptr[1][i] == '%')
            x = 5;
    }
    return (x);
}

int summands(char **str_ptr)
{
    int res = 0;
    int i = 0;

    for (; str_ptr[1][i] >= 48 && str_ptr[1][i] <= 57; i += 1);
    if (str_ptr[1][i] == '+' || str_ptr[1][i] == '*' || str_ptr[1][i] == '/'
    || str_ptr[1][i] == '-' || str_ptr[1][i] == '%')
        i += 1;
    for (; str_ptr[1][i] >= 48 && str_ptr[1][i] <= 57; i += 1) {
        res = res + str_ptr[1][i] - 48;
        if (str_ptr[1][i + 1] >= 48 && str_ptr[1][i + 1] <= 57)
            res *= 10;
    }
    return (res);
}

int sum(char **str_ptr)
{
    int res1 = number(str_ptr);
    int res2 = summands(str_ptr);
    int result = 0;

    switch (find_plus(str_ptr))
    {
    case 1:
        result = res1 + res2;
        break;
    case 2:
        result = res1 * res2;
        break;
    case 3:
        result = res1 / res2;
        break;
    case 4:
        result = res1 - res2;
        break;
    case 5:
        result = res1 % res2;
        break;
    }
    return (result);
}

int main(int ac, char **str_ptr)
{
    my_put_nbr(sum(str_ptr));
    my_putchar('\n');
}