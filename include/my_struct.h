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
    float *l_freq;
    float diff_let;
    char *store;
} ant_t;

typedef struct giant_s
{
    char *str;
    int word;
    int *word_len;
    int buffer_size;
    int keysize;
    char *key;
    int codesize;
    char *code;
    int oversize;
    char *leftover;
} giant_t;

#endif /* !MY_STRUCT_H_ */
