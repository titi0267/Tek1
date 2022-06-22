/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-timothe.coniel
** File description:
** error_str
*/
#include <unistd.h>
#include "../include/my.h"

void error_char(char c)
{
    write(2, &c, 1);
}

int disp_error(char const *str)
{
    int carac;

    carac = 0;
    while (str[carac] != '\0' ) {
        error_char(str[carac]);
        carac++;
    }
    return (0);
}