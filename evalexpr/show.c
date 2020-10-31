/*
** EPITECH PROJECT, 2020
** rffff
** File description:
** ffff
*/

#include "../include/my.h"
#include "../include/my_l.h"
#include "../include/show.h"
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

void make_calc(dstar_t *numbs, int sign)
{
    int x = my_getnbr(pop_dstar(numbs));
    int y = my_getnbr(pop_dstar(numbs));
    int store;
    char *op_r;

    op_doer(sign,&store,y,x);
    op_r = my_ntchar(store);
    push_dstar(numbs, op_r);
}

dstar_t *calculate(dstar_t *ced)
{
    int *numbers = malloc(100 * sizeof(int));
    dstar_t *numbs = init_dstar();
    char *read;

    for (int i = 0; i <my_nolen(ced); i++) {
        read = ced->value[i];
        if (sign_w(ced->value[i][0]) != 0) {
            make_calc(numbs, sign_w(ced->value[i][0]));
        } else {
            push_dstar(numbs, ced->value[i]);
        }
    }
    return(numbs);
}
