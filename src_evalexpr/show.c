/*
** EPITECH PROJECT, 2020
** rffff
** File description:
** ffff
*/

#ifndef hello
#define hello
    #define x 4
#endif
#include "include/my.h"
#include "include/my_lists.h"
#include <stdlib.h>

void op_doer(int sign ,int *store,int y,int x){
    switch (sign) {
    case 1:
        *store = y + x;
        break;
    case 2:
        *store = y - x;
        break;
    case 3:
        *store = y * x;
        break;
    case 4:
        *store = y / x;
        break;
    case 5:
        *store = y % x;
        break;
    default:
        break;
    }
}

void make_calc(my_stack_t *numbs, int sign)
{
    int x = my_getnbr(my_pop(numbs));
    int y = my_getnbr(my_pop(numbs));
    int store;
    char *op_r;

    op_doer(sign,&store,y,x);
    op_r = my_ntchar(store);
    my_push(numbs, op_r);
}

int calculate(my_stack_t *ced)
{
    int *numbers = malloc(100 * sizeof(int));
    my_stack_t *numbs = my_init();

    for (int i = 0; i <my_nolen(ced->value); i++) {
        char *read = ced->value[i];

        if (sign_w(ced->value[i][0]) != 0) {
            make_calc(numbs, sign_w(ced->value[i][0]));
        } else {
            my_push(numbs, ced->value[i]);
        }
    }
    return(my_getnbr(numbs->value[0]));
}
