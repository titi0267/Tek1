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
    for (int i = 0; i < ant->diff_let; i++)
        free(ant->line[i]);
    free(ant->l_freq);
    free(ant->reorder);
    free(ant->store);
    free(ant->line);
    free(ant->str);
    free(ant);
}

int main(int ac, char **av)
{
    ant_t *ant = malloc(sizeof(ant_t));
    ant->x = 0;
    ant->c = 1;
    ant->w = 1;
    ant->sum = 0;

    if (ant == NULL || error_arg(ac, av) != 0 || which_map(av, ant) != 0 
    || letter_freq(ant) != 0)
        return (84);
    descend_ord(ant, 0, 0, 0);
    for (int i = 0; ant->reorder[i] != '\0'; i++)
        my_printf("%c%i%c", ant->reorder[i], ant->l_freq[i], 6);
    my_printf("@");
    HuffmanCodes(ant);
    store_sentence(ant);
    bin_to_ascii(ant);
    memfree(ant);
    return (0);
}