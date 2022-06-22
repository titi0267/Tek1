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
    int amount;
    int ac;
    char l;
    char R;
    char d;
    char r;
    char t;
    int flag_count;
    char *path;
    int file_checked;
    char *flag_list;
    char **result_n;
    unsigned char **result_r;
    char **result_d;
    int core_error;
    int file_amount;
} infin_number_t;

#endif /* !MY_STRUCT_H_ */