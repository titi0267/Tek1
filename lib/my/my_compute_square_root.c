/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_compute_square_root.c
*/

int b_guess(int guess, int obj)
{
    if (guess * guess == obj) {
        return (guess);
    } else if (guess == 0) {
        return (0);
    } else {
        return (b_guess(guess - 1, obj));
    }
}

int my_compute_square_root(int nb)
{
    if (nb < 0)
        return (0);
    else
        return (b_guess(nb, nb));
}
