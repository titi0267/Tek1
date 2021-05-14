/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef my
#define my
#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct stumper_s
{
    char *buffer;
    int buffer_size;
    int line_nbr;
    int rounds;
    char *star;
    int word;
    int tries;
    int char_nbr;
    char **line;
    char *str;
} stumper_t;

int error_core(int ac);
int read_map(stumper_t *stp, char **av);
int store_map(stumper_t *stp);
int char_line(char *buff);
int nbr_line(char *buff);
int my_getnbr(char *buff);
void my_putchar(char c);
int my_putstr(char const *buff);
int get_usr_line(stumper_t *stp);
int replace_star(stumper_t *stp);
int my_strlen(char const *str);
void rm_question_mark(stumper_t *stp);
void print_first_letter(stumper_t *stp);

#endif /* !my */
