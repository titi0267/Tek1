/*
** EPITECH PROJECT, 2020
** bistromatic [WSL: Ubuntu]
** File description:
** infsubst
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my_structs.h"
#include "../include/my.h"
#include "../include/infadd.h"
#include "../include/infsubst.h"

char *insert_minus(char *right)
{
    int i = my_strlen(right);
    char *new_right = malloc(my_strlen(right) + 2);
    my_strcpy(new_right, right);
    for (; i >= 0; i--)
        new_right[i + 1] = new_right[i];
    new_right[0] = '-';
}

number_t *inf_subst(char *left, char *right)
{
    number_t *result = malloc(sizeof(number_t));

    result = infin_add(left, insert_minus(right));
    return (result);
}