/*
** EPITECH PROJECT, 2021
** antman.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** antman
*/

#include "../include/my.h"
#include <stdio.h>

void memfree(ant_t *ant)
{
    //for (int i = 0; i < 0; i++)
    //    free(ant->line[i]);
    free(ant->str);
    //free(ant->line);
    free(ant);
}
/*
int lol(void)
{
    int x = 2;
    int y = 0;

    for (; y <= x; y++) {}
    if () 
    printf("%p\n", str[0]);
    }
    return 0;
}
*/
int main(int ac, char **av)
{
    ant_t *ant = malloc(sizeof(ant_t));

    if (ant == NULL || error_arg(ac, av) != 0 || which_map(av, ant) != 0 || letter_freq(ant) != 0)
        return (84);
    else
        memfree(ant);
    return (0);
}