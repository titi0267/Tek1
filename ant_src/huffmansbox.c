/*
** EPITECH PROJECT, 2021
** huffmansbox.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** huffmansbox
*/

#include "../include/my.h"
#include <stdio.h>

int letter_freq(ant_t *ant)
{
    int c = 0;
    int x = 0;

    ant->l_freq = malloc(sizeof(int) * ant->diff_let * 4);
    if (ant->l_freq == NULL)
        return (-1);
    for (; ant->line[c] != 0; c++) {
        for (; ant->line[c][x] != '\0'; x++);
        ant->l_freq[c] = x;
        x = 0;
    }
    ant->l_freq[c] = 0;
    return (0);
}

int descend_ord(ant_t *ant, int d, int c, int y)
{
    ant->reorder = malloc(sizeof(char) * ant->diff_let + 1);
    ant->l_freq = pushswap(ant->l_freq);
    for (; ant->l_freq[d] != 0; d++) {
        if (d != 0 && ant->l_freq[d] > ant->l_freq[d - 1])
            c = 0;
        if (d != 0 && ant->l_freq[d] <= ant->l_freq[d - 1])
                c += 1;
        for (; ant->line[c] != 0; c++) {
            for (; ant->line[c][ant->x] != '\0'; ant->x++);
            if (ant->x == ant->l_freq[d]) {
                ant->reorder[y] = ant->line[c][ant->x - 1];
                y++;
                ant->x = 0;
                break;
            }
            ant->x = 0;
        }
    }
    ant->reorder[y] = '\0';
    return (0);
}

void HuffmanCodes(ant_t *ant)
{
    MinHNodelr *root = buildHuffmanTree(ant);
    int *arr = malloc(sizeof(int) * ant->diff_let);
    ant->fill_sent = malloc(sizeof(int *) * ant->diff_let);
    int top = 0;

    print_encrypt_bin(ant, root, arr, top);
}