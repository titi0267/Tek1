/*
** EPITECH PROJECT, 2020
** my_struct for the infin_add.c project by Elliot WALDVOGEL
** File description:
** my_struct
*/

#include <unistd.h>

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct infin_number
{
    int i;
    int amount;
    int *store_key;
    int *sentence;
    int strlen;
    int *encrypt;
    int fill_matrix;
    int fill_sentence;
} infin_number_t;

#endif /* !MY_STRUCT_H_ */