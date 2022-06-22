/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** heredoc
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void heredoc(char *eof, int out_fd)
{
    int eof_len = my_strlen(eof);
    char *str = NULL;
    int len = 0;

    while (1) {
        str = read_input("? ", 2);
        len = my_strlen(str);
        if (!my_strcmp(eof, str) && eof_len == len)
            break;
        write(out_fd, str, len);
        write(out_fd, "\n", 1);
        free(str);
        str = NULL;
        len = 0;
    }
}