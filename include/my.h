/*
** EPITECH PROJECT, 2020
** my.h by Elliot WALDVOGEL
** File description:
** my.h
*/

#include "my_struct.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>

#ifndef MY_H_
#define MY_H_

void my_putchar(char, infin_number_t *info);
int my_putchari(char);
void my_putcerr(char);
int my_put_nbr(int, infin_number_t *info);
unsigned int my_put_nbr_u(unsigned int, infin_number_t *info);
int my_putstr(char const *, infin_number_t *info);
void my_puterr(char *);
int my_char_isnum(char);
int my_strlen(char const *);
int my_getnbr(char const *);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *, char const *);
int my_putnbr_base(int, char const *, infin_number_t *info);
int my_putnbr_base_u(unsigned int number, const char *base, infin_number_t 
*info);
int my_putnbr_base_width(int, const char *, size_t, infin_number_t *info);
int my_putnbr_base_width_u(unsigned int number, const char *base, size_t width, 
infin_number_t *info);
int my_printf(char *, ...);
int find_index_my_printf(char *tab, char to_find);
void pchar(va_list *my_list, infin_number_t *info);
void pint(va_list *my_list, infin_number_t *info);
void pstr(va_list *my_list, infin_number_t *info);
void poct(va_list *my_list, infin_number_t *info);
void phex(va_list *my_list, infin_number_t *info);
void phun(va_list *my_list, infin_number_t *info);
void pbin(va_list *my_list, infin_number_t *info);
void pn(va_list *my_list, infin_number_t *info);
void perc(va_list *my_list, infin_number_t *info);
void pp(va_list *my_list, infin_number_t *info);
void pbs(va_list *my_list, infin_number_t *info);
void help(void);
int error_handling(int, char **);
void angle(char **av, infin_number_t *info);
void line(char **av, infin_number_t *info);
int delta_is(infin_number_t *info, sphere_t *sphere);
int solution(infin_number_t *info, sphere_t *sphere);
int find_inter(infin_number_t *info, sphere_t *sphere);
int divide_0(infin_number_t *info, sphere_t *sphere);

#endif /* !MY_H_ */