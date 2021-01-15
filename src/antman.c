/*
** EPITECH PROJECT, 2021
** antman.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** antman
*/

#include "../include/my.h"

void memfree(map_t *buffer)
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
    map_t *buffer = malloc(sizeof(map_t));

    if (buffer == NULL || wich_map(ac, av, buffer) != 0)
        return (84);
    select_word(buffer);
    print_word(buffer);
    memfree(buffer);
    return (0);
}