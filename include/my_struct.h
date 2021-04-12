/*
** EPITECH PROJECT, 2021
** my_struct.h
** File description:
** 
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
