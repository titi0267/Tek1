/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include "steps.h"

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
int my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char *, int);
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
int my_showmem(char const *,int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int fs_open_file(char const *);
void fs_understand_return_of_read(int, char *, int);
//void first_dot(char *, buffer_size_t *);
//void carac_on_line(char *, buffer_size_t *);
//void dot_under(char *, buffer_size_t *);
//void loop(char *, buffer_size_t *);
void find_square(char *, buffer_size_t *);
void square(char *, buffer_size_t *);
void calc(char *, int, buffer_size_t *);

#endif /* !MY_H_ */
