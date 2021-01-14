/*
** EPITECH PROJECT, 2021
** antman.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** antman
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    map_t *buffer = malloc(sizeof(map_t));
    int c = 0;
    int e = 0;

    if (buffer == NULL || wich_map(ac, av, buffer) != 0)
        return (84);
    for (; e < buffer->word; e++) {
        for (; buffer->line[e][c] != '\0'; c++)
            my_printf("%c", buffer->line[e][c]);
        my_printf(" ");
        c = 0;
    }
    for (int i = 0; i < e; i++) {
        free(buffer->line[i]);
    }
    free(buffer->word_len);
    free(buffer->str);
    free(buffer->line);
    free(buffer);
    return (0);
}