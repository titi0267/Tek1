/*
** EPITECH PROJECT, 2020
** annex3.c for my_printf by Elliot WALDVOGEL
** File description:
** annex3
*/

#include "../../include/my.h"
#include <stdarg.h>

void display_conversion1(int a, infin_number_t *info)
{
    my_putstr("\\00", info);
    my_putnbr_base_u(a, "01234567", info);
}

void display_conversion2(int a, infin_number_t *info)
{
    my_putstr("\\0", info);
    my_putnbr_base_u(a, "01234567", info);
}

void display_conversion3(int a, infin_number_t *info)
{
    my_putstr("\\", info);
    my_putnbr_base_u(a, "01234567", info);
}

char *convert(char *str, infin_number_t *info)
{
    int a = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] > 31 && str[i] < 127)
            my_putchar(str[i], info);
        if (str[i] >= 0 && str[i] <= 31 || str[i] == 127) {
            a = str[i] + '0' - 48;
            if (a <= 7)
                display_conversion1(a, info);
            if (a >= 8 && a <= 37)
                display_conversion2(a, info);
            if (a >= 127)
                display_conversion3(a, info);
        }
    }
}

void pbs(va_list *my_list, infin_number_t *info)
{
    char *str = va_arg(*my_list, char *);
    convert(str, info);
}