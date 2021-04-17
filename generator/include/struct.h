/*
** EPITECH PROJECT, 2021
** struct
** File description:
** structure
*/

#ifndef my_struct
#define my_struct
#define visited 1
#define unvisited 0
typedef struct pos_s
{
    struct pos_s *prev;
    struct pos_s *next;
    int line;
    int car;
    int y;
    int **visit;
    int x;
    char **maze;
} pos_t;

#endif /* !my_struct */
