/*
** EPITECH PROJECT, 2020
** my_isneg.c by Elliot WALDVOGEL
** File description:
** my_isneg
*/

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return (0);
}