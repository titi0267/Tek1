/*
** EPITECH PROJECT, 2020
** bistromatic [WSL: Ubuntu]
** File description:
** mult
*/

#include "./include/my_structs.h"
#include "./include/my.h"
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

number_t *mult_all(char *left, char *right)
{
    int carry = 0;
    int j;
    char *left_rev = my_revstr(left);
    char *right_rev = my_revstr(right);
    number_t *result = malloc(sizeof(number_t));
    int mem_len = my_strlen(left) + my_strlen(right);
    result->numb = malloc(10000000000);
    char *past = malloc(1000000000);

    my_strcpy(result->numb, "0");
    for (int i = 0; i < my_strlen(right_rev); i++) {
        for (j = 0; j < my_strlen(left_rev); j++) {
            past[j] = mult(left_rev[j], right_rev[i], &carry);
        }
        if (carry > 0)
            past[j++] = carry + '0';
        past[j]='\0';
        mult_by_10(past, i);
        printf("past at %d: %s\n", i, past);
        result->numb = infin_add(past, result->numb)->numb;
        printf("res at %d: %s\n", i, result->numb);
        carry = 0;
        my_strcpy(past, "");
    }

    my_revstr(result->numb);
    return (result);
}

int main(int ac, char **av)
{
    //char *mam=my_strdup("222");
   // mult_by_10(mam, 2);
   // printf("%s\n", mam);
  printf("hello %s\n", mult_all(my_strdup(av[1]), my_strdup(av[2]))->numb);
}
