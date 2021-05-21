/*
** EPITECH PROJECT, 2021
** 42sh [WSL: Ubuntu]
** File description:
** utils_2
*/

#include "my.h"
#include "mysh.h"

int subcmd_len(char **subcmd)
{
    int i = 0;

    for (; subcmd[i]; i++);
    return (i);
}

void my_perror(char *prefix, char *error_msg)
{
    write(2, prefix, my_strlen(prefix));
    write(2, ":", 1);
    write(2, error_msg, my_strlen(error_msg));
    write(2, "\n", 1);
}