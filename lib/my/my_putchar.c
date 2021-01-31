/*
** EPITECH PROJECT, 2020
** My_put_character by Timothy CONIEL
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_error(char *str)
{
    write(2, str, my_strlen(str));
    return (84);
}
