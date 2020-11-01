/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int empty = *b;

    *b = *a;
    *a = empty;
}