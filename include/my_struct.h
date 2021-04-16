/*
** EPITECH PROJECT, 2021
** my_struct.h
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct duo_stp_s
{
    int line_nbr;
    int char_nbr;
    char *buffer;
    char **line;
    int buffer_size;
} duo_stp_t;

#endif /* !MY_STRUCT_H_ */
