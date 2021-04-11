/*
** EPITECH PROJECT, 2021
** my_struct.h
** File description:
** sovle struct
*/

#ifndef solve
#define solve

typedef struct read_s {
    char *buffer;
    int buffer_size;
} read_t;

typedef struct solve_s {
    read_t *rd;
} solve_t;

#endif /* !solve */
