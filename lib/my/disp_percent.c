/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_percent
*/

#include <stdarg.h>
#include "my.h"

void print_percent(va_list *argu_list)
{
    char s = va_arg(*argu_list, int);

    my_putchar('%');
    //my_putchar(' ');
}