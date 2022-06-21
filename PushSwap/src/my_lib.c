/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** my_putstr
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
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
}

long long int my_getnbr(char *str)
{
    int i = 0;
    long long int j = 0;
    int n = 1;

    for (; str[i] != '\0' && (str[i] == '+' || str[i] == '-'); i++) {
        if (str[i] == '-')
            n *= -1;
    }
    while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0') {
        j = j * 10 + str[i] - 48;
        i++;
    }
    if (n == -1)
        return ((-1) * j);
    else
        return (j);
}