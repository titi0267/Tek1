/*
** EPITECH PROJECT, 2020
** task 04
** File description:
** recursive power
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    result = my_compute_power_rec(nb, p - 1) * nb;
    return (result);
}