/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_is_prime.c
*/

int treat22(int treat)
{
    if (treat == 2)
        return (1);
    else
        return (0);
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
    return (guess_prime2(nb, 2));
}