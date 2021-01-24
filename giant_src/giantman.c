/*
** EPITECH PROJECT, 2021
** giantman.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** giantman
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdio.h>

void memfree_giant(giant_t *buffer)
{
    free(buffer->key);
    free(buffer->code);
    free(buffer->leftover);
    free(buffer->str);
    free(buffer);
}

int main(int ac, char **av)
{
    giant_t *buffer = malloc(sizeof(giant_t));

    if (buffer == NULL || error_arg(ac, av) != 0 || wich_map_giant(av, buffer)
    != 0)
        return (84);
    recover_freq(buffer, 0, 1, 0);
    GHuffmanCodes(buffer);
    memfree_giant(buffer);
    return (0);
}