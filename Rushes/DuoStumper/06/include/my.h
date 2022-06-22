/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef my
#define my
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stumper_s
{
    int occurence;
    char *str;
    int arg;
    int arg_first;
    char *new_str;
    int *car_nbr;
    char *car;
    int stop;
    int flag_r;
    int t_flag;
} stumper_t;

int my_getnbr(char *buff);
void my_putchar(char c);
int my_putstr(char const *buff);
int my_strcmp(char c, char d);
int my_strlen(char const *str);
void recap_flags(stumper_t *stp, char **av);
void error_argnbr(int ac);
void find_str(int ac, char **av, stumper_t *stp);
void find_str_next(stumper_t *spt, char **av, int ac);
void no_flags(stumper_t *stp, char **av);
void free_all(stumper_t *stp);

#endif /* !my */
