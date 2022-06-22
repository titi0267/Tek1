/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

unsigned char is_valid_int(long value);
int my_is_prime(int nb);
int my_isneg(int n);

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);

int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putnbr_base(int nbr, char const *base);
int my_putstr(int fd, char const *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_show_word_array(char **tab);

unsigned char is_letter(char c);
int my_str_isalpha(char const *str);
unsigned char is_low_letter(char c);
int my_str_islower(char const *str);
unsigned char is_digit(char c);
int my_str_isnum(char const *str);
unsigned char is_printable(char c);
int my_str_isprintable(char const *str);
unsigned char is_up_letter(char c);
int my_str_isupper(char const *str);

char *my_revstr(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest ,char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_get_biggest_line(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strmerge(char *str1, char *str2);
void my_strinsert(char **str, char *insertion, int pos);
char *my_strreplace(char *str, char c, char *replace);

void my_sort_int_array(int *array, int size);
char **my_str_to_word_array(char const *str);
void my_intswap(int *a, int *b);
void my_strswap(char **a, char **b);

#endif /* !MY_H_ */
