/*
** EPITECH PROJECT, 2021
** struct
** File description:
** structure
*/

#ifndef my_struct
#define my_struct

typedef struct pos_s
{
    struct pos_s *prev;
    struct pos_s *next;
    int line;
    int car;
} pos_t;

#endif /* !my_struct */
