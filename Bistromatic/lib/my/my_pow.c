/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_pow.c
*/

int my_pow(int nb, int p)
{
    if (p < 0)
        return (0);
    else if (p > 0)
        return (nb * my_pow(nb, p - 1));
    else
        return (1);
}