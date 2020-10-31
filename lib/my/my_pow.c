/*
** EPITECH PROJECT, 2020
** Day5
** File description:
** day
*/

int my_pow(int nb, int p)
{
    if (p < 0)
        return (0);
    else if (p > 0) {
        return (nb * my_pow(nb, p - 1));
    } else
        return (1);
}