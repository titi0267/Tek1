/*
** EPITECH PROJECT, 2021
** create list by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** create_list.c
*/

#include "../include/my.h"

MinHeap_t *createMinH(ant_t *ant)
{
    MinHeap_t *minHeap = malloc(sizeof(MinHeap_t));
    minHeap->array = malloc(sizeof(MinHNodelr) * ant->diff_let);
    return (minHeap);
}

MinHNodelr *newNode(char car, int min_freq)
{
    MinHNode_t *temp = malloc(sizeof(MinHNode_t));
    temp->left = NULL;
    temp->right = NULL;
    temp->item = car;
    temp->freq = min_freq;
    return (temp);
}

void swapMinHNode(MinHNodelr **a, MinHNodelr **b)
{
    MinHNodelr *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap_t *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

MinHeap_t *createAndBuildMinHeap(ant_t *ant)
{
    MinHeap_t *minHeap = malloc(sizeof(MinHeap_t));

    minHeap->array = malloc(sizeof(MinHNodelr) * ant->diff_let);
    for (int i = 0; i < ant->diff_let; ++i)
        minHeap->array[i] = newNode(ant->reorder[i], ant->l_freq[i]);
    minHeap->size = ant->diff_let;
    return (minHeap);
}