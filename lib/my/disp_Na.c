/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_Na
*/
#include "my.h"
#include "my_struct.h"
#include <stdarg.h>

void disp_conv(unsigned int a, str_len_t *info)
{
    my_putstr("\\00", info);
    convert_base(a, 8, info);
}

void disp_conv1(unsigned int a, str_len_t *info)
{
    my_putstr("\\0", info);
    convert_base(a, 8, info);
}

void disp_conv2(unsigned int a, str_len_t *info)
{
    my_putchar('\\', info);
    convert_base(a, 8, info);
}

void convert_asc(char *str, str_len_t *info)
{
    unsigned int i = 0;

    for (int a = 0; str[a] != '\0'; a ++){
        if (str[a] < 32 || str[a] >= 127) {
            i = str[a] + '0' - 48;
            if (i <= 7)
                disp_conv(i, info);
            if (i < 32 && i > 7)
                disp_conv1(i, info);
            if (i >= 127)
                disp_conv2(i, info);
        } else if (str[a] >= 32 && str[a] < 127)
            my_putchar(str[a], info);
    }
}

void disp_nascii(va_list *argu_list, str_len_t *info)
{
    char *str = va_arg(*argu_list, char *);

    convert_asc(str, info);
}
