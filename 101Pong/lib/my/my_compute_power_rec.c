/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c by Elliot WALDVOGEL
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    if (p > 1) {
        nb *= my_compute_power_rec(nb, --p);
        return (nb);
    }
    if (nb == 0)
        return (0);
}