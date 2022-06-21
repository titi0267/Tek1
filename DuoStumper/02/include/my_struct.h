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
    char **line;
    char **temp;
    char **temp_two;
    int buffer_size;
    char *buffer;
    int line_nbr;
    int char_nbr;
    int turns;
} duo_stp_t;

#endif /* !MY_STRUCT_H_ */
