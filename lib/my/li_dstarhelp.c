/*
** EPITECH PROJECT, 2020
** HEADER
** File description:
** some
*/

#include "./include/my.h"
#include "./include/my_l.h"
#include <stdlib.h>

int my_arrlen(char **my_arr)
{
    int i = 0;
    while (my_arr[i] != NULL) {
        i++;
    }
    return (i);
}

int my_nolen(dstar_t *dt)
{
    int i = 0;
    while ((dt->value[i] != NULL) && (my_strcmp(dt->value[i], "NO") != 0))
        i++;
    return (i);
}

void fill_no(dstar_t *strr)
{
    for (int i = my_nolen(strr); strr->value[i] != NULL; i++) {
        my_strcpy(strr->value[i], "NO");
    }
}

char *my_tostr(char c)
{
    char *some = malloc(2);
    some[0] = c;
    some[1] = '\0';
    return (some);
}

int check_if_num(char num, int *store)
{
    if ((num >= '0') && (num <= '9')) {
        *store = 1;
        return (1);
    } else {
        *store = 0;
        return (2);
    }
}