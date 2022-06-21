/*
** EPITECH PROJECT, 2020
** my_is_prime.c by Elliot WALDVOGEL
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int i = 0;
    int flag = 0;
    if (nb <= 1)
        return (0);
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}