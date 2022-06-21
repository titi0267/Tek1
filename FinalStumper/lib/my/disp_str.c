/*
** EPITECH PROJECT, 2020
** PRINTF
** File description:
** disp_str
*/
#include "my.h"
#include "my_struct.h"
#include <stdarg.h>

void print_str(va_list *argu_list, str_len_t *info)
{
    char *str = va_arg(*argu_list, char *);

    my_putstr(str, info);
}
