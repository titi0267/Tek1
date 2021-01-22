/*
** EPITECH PROJECT, 2021
** antman.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** antman
*/

#include "../include/my.h"

void memfree(ant_t *buffer)
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
    ant_t *buffer = malloc(sizeof(ant_t));

    if (buffer == NULL || error_arg(ac, av) != 0 || wich_map(av, buffer) != 0 ||
        print_place(buffer) == -1)
        return (84);
    else
        memfree(buffer);
    return (0);
}