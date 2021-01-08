/*
** EPITECH PROJECT, 2021
** transform int into string by Timothy CONIEL
** File description:
** my_int_to_str.c
*/
#include "my.h"

char *my_int_str(int nb, lib_t *lib)
{
    lib->str = malloc(sizeof(char) * 15);
    lib->count = 0;
    int store = 0;

    if (nb < 0) {
        lib->str[lib->count] = '-';
        lib->count = 1;
        nb *= -1;
    }
    for (; nb != 0; lib->count++) {
        store = nb % 10;
        lib->str[lib->count] = store + '0';
        nb /= 10;
    }
    lib->str[lib->count] = '\0';
    return (lib->str);
}