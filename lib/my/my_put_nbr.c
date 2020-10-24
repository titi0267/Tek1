/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** my_putnbr
*/

int my_put_nbr(int nb)
{
    int check = 0;

    if (nb < 0) {
        if (nb == -2147483648) {
            check = 1;
            nb /= 10;
        }
        nb *= -1;
        my_putchar('-');
    }

    if (nb >= 10) {
        my_put_nbr(nb/10);
    }
    my_putchar(nb%10+48);

    if (check == 1)
        my_putchar('8');
    return (0);
}