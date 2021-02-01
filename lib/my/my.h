/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-timothe.coniel
** File description:
** my_lib by Timothy CONIEL
*/

#ifndef my_h_
#define my_h_
#include "printf/myp.h"

typedef struct lib_s
{
    int count;
    char *str;
} lib_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int nb);
int my_getnbr(char *str);
char *my_int_str(int nb, lib_t *lib);
char *my_revstr(char *str, lib_t *lib);
int my_strlen(char *str);
int my_wordnbr(char *str);
int my_error(char *str);
int my_strxcmp(char *cmp, char *cmpd);
int word_tablen(char **str);
int my_tabint(int *nbr);

#endif /* !my_h_ */
