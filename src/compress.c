/*
** EPITECH PROJECT, 2021
** compress by Timothy CONIEL & Elliot Waldvogel
** File description:
** compress.c
*/

#include "../include/my.h"

void select_word(map_t *buffer)
{
    int i = 0;
    buffer->wch = 0;
    int h = 0;
    int s = 0;
    int c = 0;

    buffer->multi_word = malloc(sizeof(int *) * 1000);
    buffer->alrd = malloc(sizeof(int) * buffer->word);
    for (int u = 0; u < buffer->word; u++)
        buffer->alrd[u] = -1;
    for (; buffer->wch < buffer->word; buffer->wch++) {
        buffer->multi_word[buffer->wch] = malloc(sizeof(int) * 1000);
        for (; i < buffer->word; i++) {
            if (my_strncmp(buffer->line[buffer->wch], buffer->line[i]) == 0) {
                buffer->multi_word[buffer->wch][h] = i;
                for (int v = 0; v < buffer->word; v++) {
                    if (buffer->alrd[v] != i)
                        c++;
                }
                h++;
                if (c == buffer->word) {
                    buffer->alrd[s] = i;
                    s++;
                }
                c = 0;
            }
        }
        i = 0;
        h = 0;
    }
}

void word_place(map_t *buffer)
{
    int x = 0;
    int c = 0;
    int e = 0;
    int s = 0;

    buffer->wrd_plc = malloc(sizeof(int *) * 100);
    for (; s <= buffer->diff_wrd; s++) {
        buffer->wrd_plc[s] = malloc(sizeof(int) * 100);
        for (; e < buffer->word && my_strncmp(buffer->line[buffer->alrd[e]], buffer->line[buffer->alrd[x]]) == 0; c++, e++)
            buffer->wrd_plc[s][c] = buffer->alrd[e];
        x = e;
        c = 0;
    }
}

void print_word(map_t *buffer)
{
    my_printf("%s@", buffer->line[buffer->alrd[0]]);
    buffer->diff_wrd = 0;
    for (int i = 0; i < buffer->word; i++) {
        if (i > 0) {
            if (my_strncmp(buffer->line[buffer->alrd[i - 1]], buffer->line[buffer->alrd[i]]) != 0) {
                my_printf("%s", buffer->line[buffer->alrd[i]]);
                my_printf("@");
                buffer->diff_wrd++;
            }
        }
    }
    word_place(buffer);
    my_printf("\n");
    my_printf("first wd = %i\n", buffer->wrd_plc[1][2]);
}