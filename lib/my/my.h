/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
int print_float(float );
void print_char(va_list *);
void print_str(va_list *);
int find_flag(char *, char);
void my_printf(char *, ...);
void print_nbr(va_list *);
void print_percent(va_list *);
void print_unsigned(va_list *);
void print_bin(va_list *);
unsigned int my_put_uint(unsigned int);
int convert_base(int, int);
void disp_oct(va_list *);
void disp_hex(va_list *);

#endif /* !MY_H_ */
