/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
char *my_ntchar(int nb);
int check_if_num(char num, int *store);
char *my_tostr(char c);
int sign_d(char *sign, int par);
int sign_w(char s);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int check_if_sign(char s, int *inf);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_pow(int nb, int power);
int my_str_islower(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_compute_square_root(int nb); 
int my_str_isupper(char const *str);
int my_find_prime_sup(int nb); 
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int num_len(int num);
int arr_to_num(int *arr_to_num);
int arr_sum(int *arr);
char *my_strdup(char const *str);

#endif /* !MY_H_ */