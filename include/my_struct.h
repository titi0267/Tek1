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
    int word;
    int *word_len;
    int **multi_word;
    int *alrd;
    int wch;
    int **wrd_plc;
    int diff_wrd;
    int wrd_nbr;
    int i;
    int h;
    int p;
    char *car;
} ant_t;

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
