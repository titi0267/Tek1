/*
** EPITECH PROJECT, 2021
** huffmanstree_bis.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** huffmanstree_bis
*/

#include "../include/my.h"

void gminHeapify(GMinHeap_t *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < 
    minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < 
    minHeap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swapgMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
        gminHeapify(minHeap, smallest);
    }
}

GMinHeap_t *createAndBuildgMinHeap(giant_t *buffer)
{
    GMinHeap_t *minHeap = malloc(sizeof(GMinHeap_t));
    minHeap->array = malloc(sizeof(GMinHNodelr) * buffer->diff_le);

    for (int i = 0; i < buffer->diff_le; ++i)
        minHeap->array[i] = newgNode(buffer->in_order[i], buffer->le_freq[i]);
    minHeap->size = buffer->diff_le;
    return (minHeap);
}

GMinHNodelr *extractgMin(GMinHeap_t *minHeap)
{
    GMinHNodelr *temp = minHeap->array[0];

    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    gminHeapify(minHeap, 0);
    return (temp);
}