/*
** EPITECH PROJECT, 2020
** Bistro
** File description:
** police.c
*/
#include "include/my_structs.h"
#include "include/police.h"
#include "include/my.h"
#include "include/operations.h"
#include <stdlib.h>

void destroy_minus(char *ar_one)
{
    for (int i = 0; ar_one[i] != '\0'; i++)
        ar_one[i] = ar_one[i + 1];
}

void recreate_number(char **ar1, char **ar2)
{
    int sup_len =
        (my_strlen(*ar1) > my_strlen(*ar2)) ? my_strlen(*ar1) : my_strlen(*ar2);
    int inf_len =
        (my_strlen(*ar1) < my_strlen(*ar2)) ? my_strlen(*ar1) : my_strlen(*ar2);
    char *nope = (my_strlen(*ar1) < my_strlen(*ar2)) ? *ar1 : *ar2;
    char *new = malloc(sizeof(char) * (sup_len + 1));

    if (sup_len == inf_len)
        return;
    for (int i = 0; i < (sup_len - inf_len); i++)
        new[i] = '0';
    my_strcpy((new + sup_len - inf_len), nope);
    new[sup_len] = '\0';
    if (my_strcmp(*ar1, nope) == 0) {
        free(*ar1);
        *ar1 = new;
    } else if (my_strcmp(*ar2, nope) == 0) {
        free(*ar2);
        *ar2 = new;
    }
}

number_t *adapt_numbers(char **ar1, char **ar2, number_t *one, number_t *two)
{
    opossom_t *ops = malloc(sizeof(opossom_t));
    number_t *result;

    det_signs(*ar1, *ar2, &(one->sign), &(two->sign));
    clear_o(*ar1);
    clear_o(*ar2);
    recreate_number(ar1, ar2);
    one->numb = *ar1;
    two->numb = *ar2;
    greater(one, two);
    det_operation(one, two, ops);
    result = calc_f(one, two, ops);
    return (result);
}

void det_operation(number_t *num1, number_t *num2, opossom_t *ops)
{

    ops->sign = num1->sign;
    if (ops->sign == 1) {
        if (num2->sign == 1)
            ops->op = 1;
        else if (num2->sign == -1)
            ops->op = -1;
    } else if (ops->sign == -1) {
        if (num2->sign == -1)
            ops->op = 1;
        else if (num2->sign == 1)
            ops->op = -1;
    }
}

int my_nblen(char *num)
{
    int count = 0;
    int swi = 0;

    for (int i = 0; num[i] != '\0'; i++) {
        if (num[i] != '0' && swi != 1)
            swi = 1;
        if (swi == 1)
            count++;
    }
    return (count);
}