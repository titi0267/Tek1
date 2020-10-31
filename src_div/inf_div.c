/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** inf_sous
*/
#include "include/my.h"

int operant(char *left, char *right)
{
    int count = 0;
    int first_num = 1;
    int second_num = 1;

    for (int i = 0; is_num(left[i]) != 1; i ++) {
        if (left[i] == '-')
            count ++;
    }
    if ((count % 2) == 1)
        first_num = -1;
    count = 0;
    for (int i = 0; is_num(right[i]) != 1; i ++) {
        if (right[i] == '-')
            count ++;
    }
    if (count % 2 == 1)
        second_num = -1;
    return (first_num * second_num);
}

void rm_isnotnum(char *left, char *right, char **new_left, char **new_right)
{
    int i = 0;

    for (; is_num(left[i]) != 1; i++);
    *new_left = my_strdup(left + i);
    i = 0;
    for (; is_num(right[i]) != 1; i++);
    *new_right = my_strdup(right + i);
}

int is_div(char *left, char *right, int size)
{
    char *cpy_left = my_strdup(left);

    cpy_left[size] = '\0';
}

char *len_strdiv(char *left, char *right)
{
    number_t *nykt;
    char *result;
    char *cpy_right = my_strdup(right);
    int len;

    for (int i = 0; len > 0; i++) {
        nykt = infin_add(left, right);
        if (nykt->sign == -1)
            result = '0';
        else
            right = right + right;
    }
}

number_t *inf_div(char *left, char *right)
{

}


int main(int ac, char **av)
{
    char *new_left = av[1];
    char *new_right = av[2];

    rm_isnotnum(av[1], av[2], &new_left, &new_right);
    printf("%s\n%s", new_left, new_right);
}