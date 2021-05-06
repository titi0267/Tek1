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
    int stop;
} stumper_t;

int my_getnbr(char *buff);
void my_putchar(char c);
int my_putstr(char const *buff);
int my_strcmp(char c, char d);
int my_strlen(char const *str);
void error_argnbr(int ac, char **av);
void find_str(int ac, char **av, stumper_t *stp);
void find_str_next(stumper_t *spt, char **av, int ac);

#endif /* !my */
