/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-bsmyprintf-sylvian.burn
** File description:
** my_printf.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int char_to_int(char *str, int i)
{
    char c = str[i];
    int cara = c;

    return (cara);
}

int find_flag(char *tab_flags, char element)
{
    int index = 0;
    for (index = 0; tab_flags[index] != 0; index++) {
        if (tab_flags[index] == element)
            return (index);
    }
    return (-1);
}

void my_printf(char *src, ...)
{
    void (*flag_function[5]) (va_list *) = { my_print_str, my_print_char,
        my_print_nbr, my_print_nbr, my_print_unsigned_nbr };
    char tab_flags[6] = {'s', 'c', 'd', 'i', 'u', 0};
    int tmp_flag = 0;
    int i = 0;
    va_list to_print;

    va_start(to_print, src);
    for (i = 0; src[i] != '\0'; i++) {
        if (i != 0 && src[i - 1] == '%') {
            find_percentage(src, i);
            tmp_flag = find_flag(tab_flags, src[i]);
            if ( tmp_flag != -1) {
                (*flag_function[tmp_flag]) (&to_print);
            }
        } else if (src[i] != '%') {
            my_putchar(src[i]);
        }
    }
    va_end (to_print);
}