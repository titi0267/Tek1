/*
** EPITECH PROJECT, 2020
** My_structure by Timothy CONIEL
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct ant_s
{
    int buffer_size;
    char *str;
    char **line;
    int *l_freq;
    int diff_let;
    char *store;
    char *reorder;
    char *bin_str;
    int **fill_sent;
    int bin_size;
    char *temp;
    char *compress;
} ant_t;

typedef struct MinHNode {
  char item;
  int freq;
  struct MinHNode *left;
  struct MinHNode *right;
} MinHNode_t, MinHNodelr;

typedef struct MinHeap {
  int size;
  struct MinHNode **array;
} MinHeap_t;

typedef struct giant_s
{
    char *str;
    int word;
    int *word_len;
    int buffer_size;
    char **line;
    int wch;
    int i;
    int h;
    int **multi_word;
    int *alrd;
    int **wrd_plc;
    int diff_wrd;
    int p;
    int wrd_nbr;
} giant_t;

#endif /* !MY_STRUCT_H_ */
