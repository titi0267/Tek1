/*
** EPITECH PROJECT, 2020
** task07
** File description:
** put nbr
*/

int neg(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        return (nb * -1);
    } else {
        return (nb);
    }
}

int break_number(int n, int m)
{
    while (n > m)
        n = n / 10;
    return (n%10);
}

int my_put_nbr(int nb)
{
    long m = 10;

    nb = neg(nb);
    while (m < nb) {
        my_putchar(break_number(nb, m) + 48);
        m = m * 10;
    }
    my_putchar(nb % 10 + 48);
}