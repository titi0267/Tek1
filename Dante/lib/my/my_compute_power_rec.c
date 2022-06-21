/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int res = 1;

    if (p < 0) {
        return (0);
    } else if (p == 0) {
        return (1);
    } else {
        res = my_compute_power_rec(nb, p) * my_compute_power_rec(res, p);
    }
    return (res);
}
