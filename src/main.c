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
    my_printf("%c would %s %d ice-cream %s %u bananas !\n", 'I', "like", 123456, "and", 4294967295);
    my_printf("I would%s %d of them\n", "ate", 89);
    my_printf("This should be 5 in binary numbers %b \n", 10);
    //printf("%u and %%of and banana %u", 40, 4294967296);
}