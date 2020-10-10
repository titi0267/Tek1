/*
** EPITECH PROJECT, 2020
** task01
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}