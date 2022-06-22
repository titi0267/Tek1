/*
** EPITECH PROJECT, 2020
** my_printf.c by Elliot WALDVOGEL
** File description:
** my_printf
*/

#include "../../include/my.h"
#include "../../include/my_struct.h"
#include <stdarg.h>
#include <stdlib.h>

int find_index(char *tab, char to_find)
{
    for (int i = 0; tab[i] != 0; ++i) {
        if (tab[i] == to_find)
            return (i);
    }
    return (-1);
}

int my_printf_core(char *src, va_list *my_list, infin_number_t *info)
{
    int index = 0;
    void (*tabFunction[13]) (va_list *, infin_number_t *) = {pchar, pint, pint,
     pstr, poct, phex, phex, phun, pbin, pn, perc, pp, pbs};
    char tab_index[14] = {'c', 'd', 'i', 's', 'o', 'x', 'X', 'u', 'b', 'n', '%'
    , 'p', 'S', 0};

    for (int i = 0; src[i] != 0; ++i) {
        if (i != 0 && src[i - 1] == '%' && src[i] != ' ') {
            index = find_index(tab_index, src[i]);
            if (index == -1)
                return (84);
            else
                (*tabFunction[index]) (my_list, info);
        }
        else if (src[i] != '%')
            my_putchar(src[i], info);
    }
    return (0);
}

int my_printf(char *src, ...)
{
    int to_return = 0;
    va_list my_list;
    infin_number_t *info = malloc(sizeof(infin_number_t));

    info->amount = 0;
    va_start(my_list, src);
    to_return = my_printf_core(src, &my_list, info);
    if (to_return == 0) {
        return (info->amount);
    }
}