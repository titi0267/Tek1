/*
** EPITECH PROJECT, 2020
** my_swap.c Elliot WALDVOGEL
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int cp = 0;

    cp = *a;
    *a = *b;
    *b = cp;
}
