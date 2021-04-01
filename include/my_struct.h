/*
** EPITECH PROJECT, 2020
** My_structure by Timothy CONIEL
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct duo_stp_s
{
    char **nbrs;
    int len;
    int *fd;
    char **store_buf;
    char *buffer;
    int buffer_size;
} duo_stp_t;

#endif /* !MY_STRUCT_H_ */
