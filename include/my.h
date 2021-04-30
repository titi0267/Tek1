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
    int word;
    int tries;
    int char_nbr;
    char **line;
    char *str;
} stumper_t;

int error_core(int ac, char **av, stumper_t *stp);
int read_map(stumper_t *stp, char **av);
int store_map(stumper_t *stp);
int char_line(char *buff);
int nbr_line(char *buff);
int my_getnbr(char *buff);
void my_putchar(char c);
int my_putstr(char const *buff);
int get_usr_line(stumper_t *stp);
void error_argnbr(int ac, char **av);
int replace_star(stumper_t *stp);
int my_strlen(char const str);
int my_strcmp(char const *s1, char const *s2);

#endif /* !my */
