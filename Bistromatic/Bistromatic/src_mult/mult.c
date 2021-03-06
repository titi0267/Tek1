/*
** EPITECH PROJECT, 2020
** bistromatic [WSL: Ubuntu]
** File description:
** mult
*/

#include "../include/my_structs.h"
#include "../include/my.h"
#include "../include/mult.h"
#include "../include/infmodul.h"
#include "../include/div_help.h"
#include <stdlib.h>
#include <stdio.h>

number_t *infin_add(char *n1, char *n2);

// void carry_writer(char *dest, int *carry)
// {
//     for(int i = 0; )
// }

char mult(char left, char right, int *carry)
{
    int left_n = left - '0';
    int right_n = right - '0';
    int mult = left_n * right_n + *carry;
    int remain = mult % 10;

    *carry = mult / 10;
    return (remain + '0');
}

void *mult_by_10(char *to_mult, long long p10)
{
    long long i;

    for (long long j = 0; j < p10; j++) {
        i = my_strlen(to_mult);
        for (; i >= 0; i--) {
            to_mult[i + 1] = to_mult[i];
        }
        to_mult[j] = '0';
    }
}

void free_mult(char *left, char *right, char *past)
{
    free(left);
    free(right);
    free(past);
}

void mult_inside(char *left_rev, char *right_rev, char *result)
{
    int j = 0;
    int carry = 0;
    char *past = malloc(my_strlen(left_rev) + my_strlen(right_rev) + 3);

    my_strcpy(result, "0");
    for (int i = 0; i < my_strlen(right_rev); i++) {
        for (j = 0; j < my_strlen(left_rev); j++) {
            past[j] = mult(left_rev[j], right_rev[i], &carry);
        }
        if (carry > 0)
            past[j++] = carry + '0';
        past[j] = '\0';
        mult_by_10(past, i);
        my_strcpy(
            result,
            my_revstr(infin_add(my_revstr(past), my_revstr(result))->numb));
        carry = 0;
        my_strcpy(past, "");
    }
}

char *mult_all(char *left, char *right)
{
    left = my_strdup(left);
    right = my_strdup(right);
    int carry = 0;
    int j;
    char *left_rev = my_revstr(left);
    char *right_rev = my_revstr(right);
    int mem_len = my_strlen(left) + my_strlen(right);
    char *result = malloc(mem_len + 3);
    char *past = malloc(mem_len + 3);

    mult_inside(left_rev, right_rev, result);
    free_mult(left, right, past);
    my_revstr(result);
    return (result);
}

number_t *inf_mult(char *left, char *right)
{
    left = my_strdup(left);
    right = my_strdup(right);
    int sign = operant(left, right);

    rm_isnotnum(left, right, &left, &right);
    number_t *result = malloc(sizeof(number_t));
    result->numb = mult_all(left, right);
    result->sign = sign;
    return (result);
}

// int main(int ac, char **av)
// {
//     print_numbert(inf_mult(av[1],av[2]));
// }
