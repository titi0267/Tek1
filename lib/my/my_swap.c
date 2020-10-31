/*
** EPITECH PROJECT, 2020
** Cpool day 4
** File description:
** gfs
*/

void my_swap(int *a, int *b)
{
    int empty = *b;

    *b = *a;
    *a = empty;
}