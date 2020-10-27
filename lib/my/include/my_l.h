/*
** EPITECH PROJECT, 2020
** gg
** File description:
** gg
*/

#ifndef STARS_H
#define STARS_H
typedef struct dstar {
    char **value;
    int mem_len;
} dstar_t;

dstar_t *my_test();
void re_dstar(dstar_t *to_re);
void push_dstar(dstar_t *to_push, char const *value);
char *pop_dstar(dstar_t *to_pop);
dstar_t *init_dstar();
const char *MY_NULL;
int my_nolen(char **my_arr);
void fill_no(char **strr);
#endif

