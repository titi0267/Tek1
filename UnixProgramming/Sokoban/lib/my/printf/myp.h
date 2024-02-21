/*
** EPITECH PROJECT, 2020
** my from my_printf by Timothy CONIEL
** File description:
** my.h
*/

#ifndef MYP_H_
#define MYP_H_
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct str_len_s {
    int buf_size;
} str_len_t;

void my_putcharp(char, str_len_t *);
int my_putnbrp(int, str_len_t *);
int my_putstrp(char const *, str_len_t *);
void print_char(va_list *, str_len_t *);
void print_str(va_list *, str_len_t *);
int find_flag(char *, char);
int my_printf(char *, ...);
void print_nbr(va_list *, str_len_t *);
void print_unsigned(va_list *, str_len_t *);
void print_bin(va_list *, str_len_t *);
unsigned int my_put_uint(int, str_len_t *);
void disp_oct(va_list *, str_len_t *);
void disp_hexa(va_list *, str_len_t *);
void disp_hex(va_list *, str_len_t *);
void my_vprintf(char *, str_len_t *, va_list *);
int convert_minus(int, str_len_t *);
void convert_base(unsigned int, int, str_len_t *);
void convert_hexa(unsigned int, str_len_t *);
void convert_hex(unsigned int, str_len_t *);
void store_len(va_list *, str_len_t *);
void print_ad(va_list *, str_len_t *);
void convert_ad(uintmax_t, str_len_t *);
void disp_nascii(va_list *, str_len_t *);
char *my_strcpyp(char *, char const *);

#endif /* !MYP_H_ */
