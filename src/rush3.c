/*
** EPITECH PROJECT, 2020
** rush3.c by Elliot WALDVOGEL
** File description:
** rush3
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_struct.h"

void rush3(char *buff)
{
    my_putstr(buff);
}

int main(int ac, char **av)
{
    int buff_size = 2147483647;
    char *buff = malloc(sizeof(char) * buff_size);
    int offset = 0;
    int len;
    while ((len = read(0, buff + offset, buff_size - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
         return (84);
    rush3(buff);
    return (0);
}