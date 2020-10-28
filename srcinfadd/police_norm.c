/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** police_norm
*/
#include "include/my_structs.h"
#include "include/my.h"
#include "include/police.h"
#include "include/operations.h"

void first_oc(char *num1, char *num2, int *first, int *second)
{

    for (int i = 0; num1[i] != '\0'; i++) {
        if (num1[i] != num2[i]) {
            *first = num1[i] - '0';
            *second = num2[i] - '0';
            return;
        }
    }
    *first = 0;
    *second = 0;
}

void greater(number_t *num1, number_t *num2)
{
    int num1_len = my_nblen(num1->numb);
    int num2_len = my_nblen(num2->numb);
    int first;
    int second;

    if (num1_len == num2_len) {
        first_oc(num1->numb, num2->numb, &first, &second);
        if (first < second)
            ex_numbers(num1, num2);
    } else if (num1_len < num2_len)
        ex_numbers(num1, num2);
}

void det_signs(char *ar1, char *ar2, int *one, int *two)
{
    /*char *ar1_one = *ar1;
    char *ar2_one = *ar2;*/
    if (ar1[0] == '-') {
        *one = -1;
        destroy_minus(ar1);
    } else
        *one = 1;
    if (ar2[0] == '-') {
        *two = -1;
        destroy_minus(ar2);
    } else
        *two = 1;
}

void ex_numbers(number_t *num1, number_t *num2)
{
    char *store_num = num1->numb;
    int store_sign = num1->sign;

    num1->numb = num2->numb;
    num1->sign = num2->sign;
    num2->numb = store_num;
    num2->sign = store_sign;
}
