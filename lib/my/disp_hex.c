/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_hex
*/

#include "my.h"
#include "my_struct.h"
#include <stdarg.h>

void disp_hex(va_list *argu_list, str_len_t *info)
{
    int e = va_arg(*argu_list, int);

    convert_hex(e, info);
    //my_putstr(f, info);
}