<<<<<<< HEAD
/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** div_help
*/

#include "./include/my_structs.h"
#include "./include/my.h"
#include "./include/mult.h"
=======
#include "../include/my_structs.h"
#include "../include/my.h"
#include "../include/infadd.h"
#include "../include/mult.h"
>>>>>>> 975c00a18b73f8dcf1b6587e7e50fe5965e4769d
#include <stdio.h>
#include <stdlib.h>

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

char get_lastch(char *to_getlast)
{
    int i = 0;

    while (to_getlast[i] != '\0')
        i++;
    return (to_getlast[i - 1]);
}

char *my_tostr(char c)
{
    char *some = malloc(2);

    some[0] = c;
    some[1] = '\0';
    return (some);
}

int bigger_num(char *left, char *right)
{
    int i;
    int count = 0;

    if (my_strlen(left) > my_strlen(right))
        return (1);
    if (my_strlen(left) == my_strlen(right)) {
        for (i = 0; left[i] != '\0'; i++) {
            if(left[i] > right[i] && count == i)
                return(1);
             if(left[i] >= right[i] && count == i && left[i+1] == '\0')
                return(1);
             if(left[i] >= right[i])
                count++;
        }
    }
    return (0);
}

char *insert_minus(char *right)
{
    int i = my_strlen(right);
    char *new_right = malloc(my_strlen(right) + 2);

    my_strcpy(new_right, right);
    for (; i >= 0; i--)
        new_right[i + 1] = new_right[i];
    new_right[0] = '-';
}

static number_t *subst(char *left, char *right)
{
    number_t *result = malloc(sizeof(number_t));

    result = infin_add(left, insert_minus(right));
    return (result);
}

char *do_div(char *left, char *right, char **indirect)
{
    char *i = my_strdup("0");
    char *new_left = my_strdup(left);
    number_t *result = malloc(sizeof(number_t));
    
    result->sign = 0;
    for (; result->sign != -1; i = infin_add(i, "1")->numb) {
        result = subst(new_left, right);
        free(new_left);
        new_left = result->numb;
    }
    i = subst(i, "1")->numb;
    *indirect = my_strdup(subst(left, inf_mult(right, i)->numb)->numb);
    return (i);
}

char *divi(char *left, char *right,char **rem)
{
    char *new_left = malloc(10000);
    char *result = malloc(1000);
    char *remain;
    int i = 0;

    my_strcpy(new_left, left);
    new_left[1] = '\0';
    for (i = 2; bigger_num(new_left, right) != 1; i++) {
        new_left = my_strdup(left);
        new_left[i] = '\0';
    }
    i--;
    my_strcpy(result, do_div(new_left, right, &remain));
    my_strcpy(new_left, "");
    for (int k = i; k < my_strlen(left); k++) {
        if (my_strcmp(remain, "0") != 0)
            my_strcpy(new_left, remain);
        my_strcat(new_left, my_tostr(left[k]));
        my_strcat(result, do_div(new_left, right, &remain));
        if(get_lastch(result)!='0')
            my_strcpy(new_left,"");
    }
    *rem = remain;
    return (result);
}

<<<<<<< HEAD
int main(int ac, char **av)
{
    char *remain;
    char *result;

    if (error(av[2]) == 1) {
        my_putstr("syntax error");
        return (84);
    }
    result = divi(my_strdup(av[1]),my_strdup(av[2]),&remain);
    printf("DIVISION %s\n",result);
    printf("RESTE %s\n",remain);
    // printf("res %s\n", subst(my_strdup(av[1]),my_strdup(av[2]))->numb);
}
=======

// int main(int ac, char **av)
// {
//     char *remain;
//     char *result = divi(my_strdup(av[1]),my_strdup(av[2]),&remain);
//     printf("DIVISION %s\n",result);
//     printf("RESTE %s\n",remain);
//     // printf("res %s\n", subst(my_strdup(av[1]),my_strdup(av[2]))->numb);
// }
>>>>>>> 975c00a18b73f8dcf1b6587e7e50fe5965e4769d
