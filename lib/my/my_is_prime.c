/*
** EPITECH PROJECT, 2020
** Day5
** File description:
** day
*/

int treat22(int treat)
{
    if (treat == 2) {
        return (1);
    } else {
        return (0);
    }
}

int guess_prime2(int nb, int it)
{
    if (nb <= 2)
        return (treat22(nb));
    else if ((nb % it) == 0)
        return (0);
    if ((it * it) > nb)
        return (1);
    return (guess_prime2(nb, it + 1));
}

int my_is_prime(int nb)
{
    return guess_prime2(nb, 2);
}