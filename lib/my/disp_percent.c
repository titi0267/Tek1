/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_percent
*/

#include <stdarg.h>
#include "my.h"
#include "my_struct.h"
#include <unistd.h>

/*int is_space_percent(char *str, int space)
{
    for (; str[space] != '\0'; space ++) {
        if (space != 0 && str[space] == '%' && str[space + 1] == '%' && str[space + 2] == ' ') {
            my_putchar('%');
            my_putchar(' ');
        } else if (str[space] != '%' && str[space + 1] == '%' && str[space + 2] != ' ') {
            my_putchar('%');
            my_putchar(' ');
            for (; str[space] != ' '; space ++) {
                write(1, str[space], space);
            }
            return (0);
        }
    }
}
*/
void print_percent(va_list *argu_list, str_len_t *info)
{
    char s = va_arg(*argu_list, int);

    s = '%';
    my_putchar(s, info);
}