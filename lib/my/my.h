/*
** EPITECH PROJECT, 2020
** my.h by Elliot WALDVOGEL
** File description:
** my.h
*/

#include "my_struct.h"

#ifndef MY_H_
#define MY_H_

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_strlen_non_constant(char *);
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
int compare_s1(char const *, char const *);
int compare_s2(char const *, char const *);
int my_strncmp(char const *, char const *, int);
int compare_s1n(char const *, char const *, int);
int compare_s2n(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
void display_line(char const*, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_putnbr_base(int, char const *);
char *abs_value(char *);
void analyze(infin_number_t *, char *, char *);
void analyze_op(infin_number_t *, char *, char *);
void analyze_op_bis(infin_number_t *, char *, char *);
void analyze_op_tris(infin_number_t *, char *, char *);

#endif /* !MY_H_ */