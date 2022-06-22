/*
** EPITECH PROJECT, 2021
** my library by Timothy CONIEL
** File description:
** lib.c
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_getnbr(char *str)
{
    int i = 0;
    int j = 0;
    int n = 1;

    for (; str[i] != '\0' && (str[i] == '+' || str[i] == '-'); i++) {
        if (str[i] == '-')
            n *= -1;
    }
    for (; str[i] != '\0' && str[i] <= '9' && str[i] >= '0'; i++)
        j = j * 10 + str[i] - 48;
    if (n == -1)
        return ((-1) * j);
    else
        return (j);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

int my_putnbr(int nb)
{
    int d = 1;

    if (nb == -2147483648)
        my_putstr("-2147483648");
    else {
        if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
        for (; (nb / d) >= 10; d *= 10);
        for (; d > 0; d /= 10)
            my_putchar((nb / d) % 10 + '0');
    }
    return (0);
}

int my_strncmp(char *cmp, char *cmpd)
{
    int l = 0;

    while (cmp[l] != '\0') {
        if (cmpd[l] == cmp[l])
            l++;
        else
            return (-1);
    }
    return (0);
}