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
int find_flag(char *flag_board, char flag_char);
void my_printf(char *str, ...);
void print_nbr(va_list *);

#endif /* !MY_H_ */
