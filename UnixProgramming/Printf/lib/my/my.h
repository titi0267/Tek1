/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdint.h>
#include "my_struct.h"

void my_putchar(char, str_len_t *);
int my_put_nbr(int, str_len_t *);
int my_putstr(char const *, str_len_t *);
void print_char(va_list *, str_len_t *);
void print_str(va_list *, str_len_t *);
int find_flag(char *, char);
int my_printf(char *, ...);
void print_nbr(va_list *, str_len_t *);
void print_unsigned(va_list *, str_len_t *);
void print_bin(va_list *, str_len_t *);
unsigned int my_put_uint(int, str_len_t *);
void disp_oct(va_list *, str_len_t *);
void disp_heX(va_list *, str_len_t *);
void disp_hex(va_list *, str_len_t *);
void my_vprintf(char *, str_len_t *, va_list *);
int convert_minus(int, str_len_t *);
void convert_base(unsigned int, int, str_len_t *);
void convert_heX(unsigned int, str_len_t *);
void convert_hex(unsigned int, str_len_t *);
void store_len(va_list *, str_len_t *);
void print_ad(va_list *, str_len_t *);
void convert_ad(uintmax_t, str_len_t *);
void disp_nascii(va_list *, str_len_t *);
char *my_strcpy(char *, char const *);

#endif /* !MY_H_ */
