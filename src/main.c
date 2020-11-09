/*
** EPITECH PROJECT, 2020
** PRINTF
** File description:
** main
*/

#include "../include/my.h"
#include <stdarg.h>
void my_printf(char *str, ...);

int main(void)
{
    my_printf("%c would %s an ice-cream %s %c banana !\n", 'I', "like", "and", 'a');
}