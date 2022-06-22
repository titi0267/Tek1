/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-evalexpr-sylvian.burn
** File description:
** number
*/

int number(char **str_ptr)
{
    int res = 0;
    int v = 0;

    for (; str_ptr[1][v] >= 48 && str_ptr[1][v] <= 57; v += 1) {
        res = res + str_ptr[1][v] - 48;
        if (str_ptr[1][v + 1] >= 48 && str_ptr[1][v + 1] <= 57)
            res *= 10;
    }
    if (str_ptr[1][v] > 57 && str_ptr[1][v] < 48)
        return (0);
    return (res);
}