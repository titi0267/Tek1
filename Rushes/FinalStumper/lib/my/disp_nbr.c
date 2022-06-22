/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_nbr
*/
#include "my.h"
#include "my_struct.h"
#include <stdarg.h>

void print_nbr(va_list *argu_list, str_len_t *info)
{
    int x = va_arg(*argu_list, int);

    my_put_nbr(x, info);
}
