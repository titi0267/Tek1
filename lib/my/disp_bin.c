/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** disp_bin
*/
#include "my.h"
#include <stdarg.h>

/*int binary(unsigned int i)
{
    unsigned int bin = 0;
    unsigned int rem = 0;
    unsigned int place = 1;
    while (i) {
        rem = i % 2;
        i = i / 2;
        bin = bin + (rem * i);
        place = place * 10;
    }
    convert_base(bin, 2);
}*/

void print_bin(va_list *argu_list)
{
    unsigned int i = va_arg(*argu_list, unsigned int);

    convert_base(i, 2);
}
/*
unsigned int print_bin(unsigned int i)
{
    //i = 10;

    unsigned int bin = 0;
    unsigned int rem = 0;
    unsigned int place = 1;
    while (i) {
        rem = i % 2;
        i = i / 2;
        bin = bin + (rem * place);
        place = place * 10;
    }
    my_put_uint(d);
}

// void main(unsigned int i)
// {
//     unsigned int d = 0;

//     d = convert_base(i, 8);
//     my_put_uint(d);
// }*/