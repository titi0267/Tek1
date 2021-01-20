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
    int x = 0;

    for (int i = 0; i < buffer->word; i++) {
        free(buffer->line[i]);
        free(buffer->multi_word[i]);
        if (x <= buffer->diff_wrd) {
            free(buffer->wrd_plc[x]);
            x++;
        }
    }
    free(buffer->wrd_plc);
    free(buffer->multi_word);
    free(buffer->alrd);
    free(buffer->word_len);
    free(buffer->str);
    free(buffer->line);
    free(buffer);
}

int main(int ac, char **av)
{
    giant_t *buffer = malloc(sizeof(giant_t));

    if (buffer == NULL || error_arg(ac, av) != 0 || wich_map_giant(av, buffer) != 0 ||
        print_place_giant(buffer) == -1)
        return (84);
    else
        memfree_giant(buffer);
    return (0);
}