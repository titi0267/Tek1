/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_bin
*/
#include "my.h"
#include "my_struct.h"
#include <stdarg.h>

void print_bin(va_list *argu_list, str_len_t *info)
{
    unsigned int i = va_arg(*argu_list, unsigned int);

    if (i <= 0)
        i = my_put_uint(i, info);
    convert_base(i, 2, info);
}
