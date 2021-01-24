/*
** EPITECH PROJECT, 2021
** recreate_tree by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** recreate_tree.c
*/

#include "../include/my.h"

int recover_freq(giant_t *buffer)
{
    int i = 0;
    int x = 0;
    int store = 0;
    int second = 0;
    int y = 0;

    buffer->le_freq = malloc(sizeof(int) * buffer->keysize + 1);
    buffer->in_order = malloc(sizeof(char) * buffer->keysize + 1);
    for (; buffer->key[i] != '\0'; i++) {
        if ((buffer->key[i] != '\0' || buffer->key[i + 1] != '\0') && buffer->key[i + 1] == 6)
            buffer->in_order[x] = buffer->key[i];
        if ((buffer->key[i] <= 57 && buffer->key[i] >= 48) && (buffer->key[i + 1] <= 57 && buffer->key[i + 1] >= 48)) {
            while (buffer->key[i + 1] != '\0') {
                second = store;
                store = buffer->key[i] - 48;
                if ((buffer->key[i + 1] < 48 && buffer->key[i + 1] > 57)) {
                    second = second + (buffer->key[i] - 48);
                    break;
                }
                else
                    store *= 10;
                i++;
            }
            buffer->le_freq[y] = second;
            y++;
        }
        if ((buffer->key[i] != '\0' || buffer->key[i + 1] != '\0') && buffer->key[i + 1] <= 57 && buffer->key[i + 1] >= 48)
            buffer->le_freq[x] = buffer->key[i];
    }
    return (0);
}