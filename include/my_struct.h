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
    char *str;
    int size;
    char **line_map;
    int word;
    int car;
    int *target_line;
    int *target_car;
    int up_on_o;
    int left_on_o;
    int quit;
} map_t;

#endif /* !MY_STRUCT_H_ */
