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
    int x = 1;
    int store = 0;
    int second = 0;
    buffer->diff_le = 0;
    int y = 0;

    buffer->le_freq = malloc(sizeof(int) * buffer->keysize + 1);
    buffer->in_order = malloc(sizeof(char) * buffer->keysize + 1);
    buffer->in_order[0] = buffer->key[0];
    for (; buffer->key[i] != '\0'; i++) {
        if (i != 0 && buffer->key[i - 1] == 6) {
            buffer->in_order[x] = buffer->key[i];
            x++;
        }
        if (buffer->key[i] >= '0' && buffer->key[i] <= '9') {
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
            buffer->le_freq[y] = second;
            store = 0;
            y++;
        }
    }
    buffer->le_freq[y] = '\0';
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

void gminHeapify(GMinHeap_t *minHeap, int idx)
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

void insertgMinHeap(GMinHeap_t *minHeap, GMinHNode_t *minHeapNode)
{
    minHeap->size++;
    int i = minHeap->size - 1;

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

    gprint_encrypt_bin(buffer, root, arr, top); /*      print binary key for each letter (keep as comment)
    for (; i < buffer->diff_le; i++) {
        my_printf("letter =  %c ->  ", buffer->in_order[i]);
        for (int c = 0; buffer->binkey[i][c] != -1; c++)
            my_printf("%i", buffer->binkey[i][c]);
        my_printf("\n");
    }*/
}
