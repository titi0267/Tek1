/*
** EPITECH PROJECT, 2020
** encryption.c for navy by Timothy CONIEL & Elliot WALDOGEL
** File description:
** encryption
*/

#define _XOPEN_SOURCE 700
#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
extern int connect;

int encrypt(char *pos, infin_number_t *info)
{
    int encryption = 0;
    int column = char_column(pos[0]);
    int line = char_line(pos[1]);

    column = column*10;
    encryption = column + line;
    return (encryption);
}