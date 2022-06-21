/*
** EPITECH PROJECT, 2021
** frequency by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** frequency.c
*/

#include "../include/my.h"
#include <stdio.h>

MinHNodelr *extractMin(MinHeap_t *minHeap)
{
    MinHNodelr *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    minHeap->size--;
    minHeapify(minHeap, 0);
    return (temp);
}

void insertMinHeap(MinHeap_t *minHeap, MinHNode_t *minHeapNode)
{
    minHeap->size++;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}


MinHNodelr *buildHuffmanTree(ant_t *ant)
{
    MinHNode_t *left;
    MinHNode_t *right;
    MinHNode_t *top;
    MinHeap_t *minHeap = createAndBuildMinHeap(ant);

    for (int i = 0; i < ant->diff_let - 1; i++) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('*', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return (extractMin(minHeap));
}

void printArray(int *arr, int top, ant_t *ant)
{
    static int e = 0;

    ant->fill_sent[e] = malloc(sizeof(int) * (top + 1));
    for (int i = 0; i < top; i++)
        ant->fill_sent[e][i] = arr[i];
    ant->fill_sent[e][top] = -1;
    e++;
}

void print_encrypt_bin(ant_t *ant, MinHNodelr *root, int *arr, int top)
{
    static int x = 0;

    if (root->left != NULL) {
        arr[top] = 0;
        print_encrypt_bin(ant, root->left, arr, top + 1);
    }
    if (root->right != NULL) {
        arr[top] = 1;
        print_encrypt_bin(ant, root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        ant->reorder[x] = root->item;
        x++;
        printArray(arr, top, ant);
    }
}