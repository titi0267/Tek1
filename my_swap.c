/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday03-timothe.coniel
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}