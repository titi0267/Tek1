/*
** EPITECH PROJECT, 2021
** recreate_tree by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** recreate_tree.c
*/

#include "../include/my.h"

void insertgMinHeap(GMinHeap_t *minHeap, GMinHNode_t *minHeapNode)
{
    int i = 0;

    minHeap->size++;
    i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

GMinHNodelr *buildHuffmangTree(giant_t *buffer)
{
    GMinHNode_t *left;
    GMinHNode_t *right;
    GMinHNode_t *top;
    GMinHeap_t *minHeap = createAndBuildgMinHeap(buffer);

    for (int i = 0; i < buffer->diff_le - 1; i++) {
        left = extractgMin(minHeap);
        right = extractgMin(minHeap);
        top = newgNode('*', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertgMinHeap(minHeap, top);
    }
    return (extractgMin(minHeap));
}

void printgArray(int *arr, int top, giant_t *buffer)
{
    static int e = 0;

    buffer->binkey[e] = malloc(sizeof(int) * (top + 1));
    for (int i = 0; i < top; i++)
        buffer->binkey[e][i] = arr[i];
    buffer->binkey[e][top] = -1;
    e++;
}

void gprint_encrypt_bin(giant_t *buffer, GMinHNodelr *root, int *arr, int top)
{
    static int x = 0;

    if (root->left != NULL) {
        arr[top] = 0;
        gprint_encrypt_bin(buffer, root->left, arr, top + 1);
    }
    if (root->right != NULL) {
        arr[top] = 1;
        gprint_encrypt_bin(buffer, root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        buffer->in_order[x] = root->item;
        x++;
        printgArray(arr, top, buffer);
    }
}

void GHuffmanCodes(giant_t *buffer)
{
    GMinHNodelr *root = buildHuffmangTree(buffer);
    int *arr = malloc(sizeof(int) * buffer->diff_le);
    buffer->binkey = malloc(sizeof(int *) * buffer->diff_le);
    int top = 0;
    int i = 0;

    gprint_encrypt_bin(buffer, root, arr, top); //      print binary key for each letter (keep as comment)
    for (; i < buffer->diff_le; i++) {
        my_printf("letter =  %c ->  ", buffer->in_order[i]);
        for (int c = 0; buffer->binkey[i][c] != -1; c++)
            my_printf("%i", buffer->binkey[i][c]);
        my_printf("\n");
    }
}
