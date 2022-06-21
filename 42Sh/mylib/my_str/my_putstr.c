/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** print each character of a string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(int fd, char const *str)
{
    int len = my_strlen(str);

    write(fd, str, len);
    return (0);
}