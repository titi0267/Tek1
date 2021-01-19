/*
** EPITECH PROJECT, 2021
** solo_stumper by Timothy CONIEL
** File description:
** solo_stumper.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>

int error(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Error : not enough arguments.\n", 30);
        return (84);
    }
    return (0);
}

int count_anag(char **av)
{
    int c = 0;
    int count = 0;

    for (; av[1][c] != '\0'; c++) {
        for (int x = 0; av[2][x] != '\0'; x++) {
            if (av[1][c] == av[2][x])
                count++;
        }
    }
    return (count);
}

int anagram(int ac, char **av)
{
    int len = 0;
    int len2 = 0;

    for (int c = 0; av[1][c] != '\0'; c++)
        len++;
    for (int x = 0; av[2][x] != '\0'; x++)
        len2++;
    if (count_anag(av) == len && len == len2)
        return (1);
    else
        return (2);
    return (0);
}

int main(int ac, char **av)
{
    if (error(ac, av) != 0)
        return (84);
    if (anagram(ac, av) == 1)
        write(1, "anagram!\n", 9);
    else if (anagram(ac, av) == 2)
        write(1, "no anagrams.\n", 13);
    else
        return (84);
    return (0);
}
