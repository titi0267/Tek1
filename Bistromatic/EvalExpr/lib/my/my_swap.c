/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-infinadd-sylvian.burn
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}