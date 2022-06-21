/*
** EPITECH PROJECT, 2021
** huffmanstree.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** huffmanstree
*/

#include "../include/my.h"

void recover_freq_next(giant_t *buffer, int i, int second, int store)
{
    while (buffer->key[i] != 6) {
        second = store;
        store = buffer->key[i] - '0';
        if (buffer->key[i + 1] > 57 || buffer->key[i + 1] < 48) {
            second = second + (buffer->key[i] - '0');
            break;
        } else
            store *= 10;
        i++;
    }
    buffer->le_freq[buffer->y] = second;
    store = 0;
    buffer->y++;
}

int recover_freq(giant_t *buffer, int i, int x, int store)
{
    int second = 0;
    buffer->diff_le = 0;
    buffer->y = 0;
    buffer->le_freq = malloc(sizeof(int) * buffer->keysize + 1);
    buffer->in_order = malloc(sizeof(char) * buffer->keysize + 1);

    buffer->in_order[0] = buffer->key[0];
    for (; buffer->key[i] != '\0'; i++) {
        if (i != 0 && buffer->key[i - 1] == 6) {
            buffer->in_order[x] = buffer->key[i];
            x++;
        }
        if (buffer->key[i] >= '0' && buffer->key[i] <= '9') {
            recover_freq_next(buffer, i, second, store);
        }
    }
    buffer->le_freq[buffer->y] = '\0';
    buffer->in_order[x] = '\0';
    buffer->diff_le = x;
    return (0);
}

GMinHNodelr *newgNode(char car, int min_freq)
{
    GMinHNode_t *temp = malloc(sizeof(GMinHNode_t));

    temp->left = NULL;
    temp->right = NULL;
    temp->item = car;
    temp->freq = min_freq;
    return (temp);
}

void swapgMinHNode(GMinHNodelr **a, GMinHNodelr **b)
{
    GMinHNodelr *t = *a;

    *a = *b;
    *b = t;
}