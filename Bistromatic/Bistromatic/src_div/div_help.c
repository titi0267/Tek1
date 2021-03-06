/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** inf_sous
*/
#include "../include/my.h"
#include "../include/my_structs.h"

int error(char *right)
{
    int zero = 0;
    int j = my_strlen(right);
    int stop = 0;

    for (int i = 0; right[i] != '\0'; i ++) {
        if (right[i] == '0')
            zero++;
    }
    if (zero == j)
        stop = 1;
    return (stop);
}


int operant(char *left, char *right)
{
    int count = 0;
    int first_num = 1;
    int second_num = 1;

    for (int i = 0; check_nums(left[i]) != 1 && left[i] != '\0'; i++) {
        if (left[i] == '-')
            count ++;
    }
    if ((count % 2) == 1)
        first_num = -1;
    count = 0;
    for (int i = 0; check_nums(right[i]) != 1 && left[i] != '\0'; i++) {
        if (right[i] == '-')
            count ++;
    }
    if (count % 2 == 1)
        second_num = -1;
    return (first_num * second_num);
}

void rm_isnotnum(char *left, char *right, char **new_left, char **new_right)
{
    int i;

    for (i=0;check_nums(left[i])!=1; i++);
    *new_left = my_strdup(left + i);
    for (i=0; check_nums(right[i]) != 1; i++);
    *new_right = my_strdup(right + i);
}
