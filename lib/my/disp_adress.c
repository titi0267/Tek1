/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_adress
*/
#include "my.h"
#include "my_struct.h"
#include <stdarg.h>

void print_ad(va_list *argu_list, str_len_t *info)
{
    void *x = va_arg(*argu_list, void *);
    uintptr_t y = (uintptr_t)x;

    my_putstr("0x", info);
    convert_ad(y, info);
}
