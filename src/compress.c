/*
** EPITECH PROJECT, 2021
** compress by Timothy CONIEL & Elliot Waldvogel
** File description:
** compress.c
*/

#include "../include/my.h"

int init_select(map_t *buffer)
{
    buffer->wch = 0;
    buffer->i = 0;
    buffer->h = 0;
    buffer->multi_word = malloc(sizeof(int *) * 10000);
    buffer->alrd = malloc(sizeof(int) * buffer->word);
    if (buffer->multi_word == NULL || buffer->alrd == NULL)
        return (-1);
    for (int u = 0; u < buffer->word; u++)
        buffer->alrd[u] = -1;
    return (0);
}

void fill_multi(map_t *buffer)
{
    static int s = 0;
    int c = 0;

    for (int v = 0; v < buffer->word; v++) {
        if (buffer->alrd[v] != buffer->i)
            c++;
    }
    buffer->h++;
    if (c == buffer->word) {
        buffer->alrd[s] = buffer->i;
        s++;
    }
}

int select_word(map_t *buffer)
{
    if (init_select(buffer) == -1)
        return (-1);
    for (; buffer->wch < buffer->word; buffer->wch++) {
        buffer->multi_word[buffer->wch] = malloc(sizeof(int) * 10000);
        if (buffer->multi_word[buffer->wch] == NULL)
            return (-1);
        for (; buffer->i < buffer->word; buffer->i++) {
            if (my_strncmp(buffer->line[buffer->wch], buffer->line[buffer->i])
                == 0) {
                buffer->multi_word[buffer->wch][buffer->h] = buffer->i;
                fill_multi(buffer);
            }
        }
        buffer->i = 0;
        buffer->h = 0;
    }
    return (0);
}

int word_place(map_t *buffer)
{
    int x = 0;
    int c = 0;
    int e = 0;
    int s = 0;

    buffer->wrd_plc = malloc(sizeof(int *) * 10000);
    if (buffer->wrd_plc == NULL)
        return (-1);
    for (; s <= buffer->diff_wrd; s++) {
        buffer->wrd_plc[s] = malloc(sizeof(int) * 10000);
        if (buffer->wrd_plc[s] == NULL)
            return(-1);
        for (; e < buffer->word && my_strncmp(buffer->line[buffer->alrd[e]],
            buffer->line[buffer->alrd[x]]) == 0; c++, e++)
            buffer->wrd_plc[s][c] = buffer->alrd[e];
        buffer->wrd_plc[s][c] = -1;
        x = e;
        c = 0;
    }
    return (0);
}
