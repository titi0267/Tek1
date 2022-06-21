/*
** EPITECH PROJECT, 2020
** my_getnbr.c by Elliot WALDVOGEL
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 0;
    int n = 1;

    for (; str[i] != '\0' && (str[i] == '+' || str[i] == '-'); i++) {
        if (str[i] == '-')
            n *= -1;
    }
    while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0') {
        j = j + str[i] - 48;
        j = j * 10;
        i++;
    }
    j /= 10;
    if (n == -1)
        return ((-1) * j);
    else
        return (j);
}