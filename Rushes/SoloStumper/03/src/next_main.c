/*
** EPITECH PROJECT, 2021
** solo_stumper by Timothy CONIEL
** File description:
** solo_stumper.c
*/

#include <stdio.h>
int my_getnbr(char *str);

int error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    for (int i = 1; av[i] != 0; i++) {
        for (int e = 0; av[i][e] != '\0'; e++) {
            if (av[i][e] < 48 || av[i][e] > 57)
                return (84);
       }
   }
    if (my_getnbr(av[1]) > my_getnbr(av[2]))
        return (84);
    return (0);
}
