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