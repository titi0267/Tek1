/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-rush2-theo.grandvillain
** File description:
** my.h
*/

#include <stdint.h>
#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

int my_isneg(int);
void my_swap(int *, int *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *,char const *,int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_strisalpha(char const *);
int my_strisnum(char const *);
int my_strislower(char const *);
int my_strisupper(char const *);
int my_strisprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *,int size);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
void my_putchar(char);
int char_to_int(char *, int);
int find_flag(char *, char);
void my_printf(char *, ...);
void my_put_nbr(int);
void my_put_unsnbr(unsigned int);
void my_print_unsigned_nbr(va_list *);
void my_print_char(va_list *);
void my_putstr(char const *);
void find_percentage(char *, int);
void my_print_str(va_list *);
void my_print_nbr(va_list *);
char **my_str_to_line_array(char *);
char **my_str_to_word_array(char *);

#endif /* MY_H_ */