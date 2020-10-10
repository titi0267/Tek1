/*
** EPITECH PROJECT, 2020
** task 07
** File description:
** is prime
*/

int my_is_prime(int nb)
{
    for (int i = 2; i < nb; i++)
    {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}