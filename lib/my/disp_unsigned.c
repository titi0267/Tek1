/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_unsigned
*/
#include "my.h"
#include "my_struct.h"
#include <stdarg.h>

void print_unsigned(va_list *argu_list, str_len_t *info)
{
    unsigned int u = va_arg(*argu_list, unsigned int);

    my_put_uint(u, info);
}