/*
** EPITECH PROJECT, 2020
** PRINTF
** File description:
** main
*/

#include "../include/my.h"
#include <stdarg.h>

int main(void)
{
    my_printf("%c would %s %d ice-cream %s %i bananas !\n", 'I', "like", 123456, "and", 2);
    my_printf("I would %s %d %%  of them\n", "ate", 89);
}