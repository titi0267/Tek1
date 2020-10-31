/*
** EPITECH PROJECT, 2020
** Day5
** File description:
** day
*/

int treat2(int treat)
{
    if (treat == 2) {
        return (1);
    } else {
        return (0);
    }
}

int guess_prime23(int nb, int it)
{
    if (nb <= 2)
        return (treat2(nb));
    else if ((nb % it) == 0)
        return (0);
    if ((it * it) > nb)
        return (1);
    return (guess_prime23(nb, it + 1));
}

int my_find_prime_sup(int nb)
{
    if (guess_prime23(nb, 2)) {
        return (nb);
    } else {
        return (my_find_prime_sup(nb + 1));
    }
}