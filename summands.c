/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-evalexpr-sylvian.burn
** File description:
** summands
*/
#include "include/my.h"

int summands(char **str_ptr)
{
    int res = 0;
    int i = 0;

    for (; str_ptr[1][i] >= 48 && str_ptr[1][i] <= 57; i += 1);
    if (str_ptr[1][i] == '+')
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

    result = res1 + res2;
    return (result);
}

int main(int ac, char **str_ptr)
{
    my_put_nbr(sum(str_ptr));
    my_putchar('\n');
}