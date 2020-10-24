/*
** EPITECH PROJECT, 2020
** my_putnbr_base.c by Elliot WALDVOGEL
** File description:
** my_putnbr_base
*/

void my_putchar_pnbr(char c)
{
    write(1, &c, 1);
}

int my_strlen_pnbr(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return (count);
}

int my_putnbr_base(int nbr, char const *base)
{
    int length = my_strlen_pnbr(base);
    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar_pnbr('-');
    }
    if (nbr == 0)
        return (0);
    else
        my_putnbr_base(nbr/length, base);
    my_putchar_pnbr(base[nbr%length]);
    return (0);
}