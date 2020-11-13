/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include "my_struct.h"

void my_putchar(char, str_len_t *);
int my_put_nbr(int, str_len_t *);
int my_putstr(char const *, str_len_t *);
void print_char(va_list *, str_len_t *);
void print_str(va_list *, str_len_t *);
int find_flag(char *, char);
int my_printf(char *, ...);
void print_nbr(va_list *, str_len_t *);
void print_percent(va_list *, str_len_t *);
void print_unsigned(va_list *, str_len_t *);
void print_bin(va_list *, str_len_t *);
unsigned int my_put_uint(int, str_len_t *);
int convert_base(int, int, str_len_t *);
void disp_oct(va_list *, str_len_t *);
void disp_hex(va_list *, str_len_t *);
void my_vprintf(char *, str_len_t *, va_list *);
int convert_oct(int, int, str_len_t *);
int convert_minus(int, str_len_t *);
int convert_bin(unsigned int, int, str_len_t *);
int convert_hex(int, str_len_t *);
void store_len(va_list *, str_len_t *);
int nbr_len(int);

#endif /* !MY_H_ */
