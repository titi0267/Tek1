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

typedef struct pos_s {
    struct pos_s *prev;
    struct pos_s *next;
    int line;
    int car;
} pos_t;

typedef struct maze_s {
    int up;
    int down;
    int left;
    int right;
    int success;
    int height;
    int width;
    int **visit;
    char **maze;
    int check;
    int pos_x;
    int pos_y;
    int is_perfect;
    int prev_rand;
    int prevprev_rand;
    int prevprevprev_rand;
    int rand_nb;
} maze_t;

#endif /* !my_struct */
