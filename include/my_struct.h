/*
** EPITECH PROJECT, 2020
** My_structure by Timothy CONIEL
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct map_s
{
    int buffer_size;
    char *buffer;
    char **line;
    int lin_val;
    int char_val;
} map_t;

#endif /* !MY_STRUCT_H_ */
