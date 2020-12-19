/*
** EPITECH PROJECT, 2020
** my_struct for the infin_add.c project by Elliot WALDVOGEL
** File description:
** my_struct
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

extern int connect;

typedef struct infin_number_s
{
    int amount;
    pid_t process_id1;
    pid_t process_id2;
    int round;
    char *shot_col;
    char *shot_line;
    int player_one;
    int player_two;
    int game_done;
    int encrpt;
} infin_number_t;

typedef struct map_s
{
    int buffer_size;
    char *buffer;
    char **line;
    char **line2;
} map_t;

typedef struct pos_s
{
    int pos_size;
    char *pos_1;
    char **find_pos1;
    char *pos_2;
    char **find_pos2;
    int *column_start;
    int *column_end;
    int *line_start;
    int *line_end;
    int *column_start2;
    int *column_end2;
    int *line_start2;
    int *line_end2;
    int decrypt_col;
    int decrypt_lin;
} pos_t;

#endif /* !MY_STRUCT_H_ */