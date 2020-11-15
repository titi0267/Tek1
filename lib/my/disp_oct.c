/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** dip_oct
*/
#include "my_struct.h"
#include "my.h"
#include <stdarg.h>

void disp_oct(va_list *argu_list, str_len_t *info)
{
    unsigned int i = va_arg(*argu_list, unsigned int);

    convert_base(i, 8, info);
}
