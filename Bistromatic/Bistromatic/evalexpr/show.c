/*
** EPITECH PROJECT, 2020
** rffff
** File description:
** ffff
*/

#include "../include/my.h"
#include "../include/my_l.h"
#include "../include/my_structs.h"
#include "../include/infdiv.h"
#include "../include/infadd.h"
#include "../include/infmodul.h"
#include "../include/polish.h"
#include "../include/infsubst.h"
#include "../include/mult.h"
#include "../include/show.h"
#include <stdlib.h>

number_t *op_doer(int op_sign , char *y, char *x)
{
    number_t *store;
    char *remain;

    switch (op_sign) {
    case 1:
        store= infin_add(y,x);
        break;
    case 2:
        store= inf_subst(y,x);
        break;
    case 3:
        store= inf_mult(y,x);
        break;
    case 4:
        store= inf_div(y, x, &remain);
        break;
    case 5:
        store = inf_modul(y, x);
        break;
    default:
        break;
    }
    return(store);
}

void make_calc(dstar_t *numbs, int op_sign)
{
    char *x = pop_dstar(numbs);
    char *y = pop_dstar(numbs);

    number_t *store = op_doer(op_sign, y, x);
    if(store->sign == -1) 
        store->numb = insert_minus(store->numb);
    push_dstar(numbs, store->numb);
}

dstar_t *calculate(dstar_t *ced)
{
    dstar_t *numbs = init_dstar();

    for (int i = 0; i <my_nolen(ced); i++) {
        if (sign_w(ced->value[i][0]) != 0 && is_all_num(ced->value[i]) == 0) {
            make_calc(numbs, sign_w(ced->value[i][0]));
        } else {
            push_dstar(numbs, ced->value[i]);
        }
        
    }
   // sh_dstar(numbs);
    return(numbs);
}
