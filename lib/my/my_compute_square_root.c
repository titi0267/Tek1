/*
** EPITECH PROJECT, 2020
** Day5
** File description:
** day
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
    if (nb < 0) {
        return (0);
    } else
        return (b_guess(nb, nb));
}
