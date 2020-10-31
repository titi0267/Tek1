/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** operations
*/
#include "../include/my_structs.h"
#include "../include/operations.h"
#include "../include/my.h"
#include "../include/police.h"
#include <stdlib.h>
#include <stdio.h>

char sum(char a, char b, int *indirect)
{
    int a_num = a - '0';
    int b_num = b - '0';
    int sumed;

    if ((a_num + b_num + *indirect) < 10) {
        sumed = a_num + b_num + *indirect;
        *indirect = 0;
    } else {
        sumed = (a_num + b_num + *indirect) % 10;
        *indirect = 1;
    }
    return (sumed + '0');
}

char subst(char a, char b,int *indirect)
{
    int a_num = a - '0';
    int b_num = b - '0';
    int substed;

    if ((a_num - b_num - *indirect) >= 0) {
        substed = a_num - b_num - *indirect;
        *indirect = 0;
    } else {
        substed = ((a_num + 10) - b_num - *indirect) % 10;
        *indirect = 1;
    }

    return (substed + '0');
}

number_t *calc_f(number_t *one, number_t *two, opossom_t *ops)
{
    number_t *result;

    if (ops->op == 1)
        result = driver(one, two, ops, &sum);
    else if (ops->op == -1)
        result = driver(one, two, ops, &subst);
    free(one);
    free(two);
    clear_o(result->numb);
    return (result);
}

number_t *driver(number_t *one, number_t *two, opossom_t *ops,
                 char (*sum_f)(char, char, int *))
{
    number_t *to_return = malloc(sizeof(number_t));
    to_return->sign = ops->sign;
    int tot_len = my_strlen(one->numb);
    int indirect=0;

    to_return->numb = malloc(tot_len + 2);
    for (int i = tot_len-1; i >= 0; i--) {
        to_return->numb[i+1] =
            (*sum_f)(one->numb[i], two->numb[i], &indirect);
        if (i == 0 && indirect == 1) {
            to_return->numb[0] = '1';
        } else if (i == 0 && indirect == 0) {
            to_return->numb[0] = '0';
        }
    }
    to_return->numb[tot_len + 1] = '\0';
    return (to_return);
}

void clear_o(char *witho)
{
    int to_m = my_nblen(witho) + 1;
    char *handler = malloc(to_m);
    int writes = 0;
    int index = 0;

    if (my_nblen(witho) == 0) {
        handler = my_strdup("0");
        my_strcpy(witho, handler);
        return;
    }
    for (int i = 0; witho[i] != '\0'; i++) {
        if (witho[i] != '0' && writes != 1)
            writes = 1;
        if (writes) {
            handler[index] = witho[i];
            index++;
        }
    }
    handler[index] = '\0';
    my_strcpy(witho, handler);
}