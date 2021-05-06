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

#endif /* !my */
