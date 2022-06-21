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
