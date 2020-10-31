/*
** EPITECH PROJECT, 2020
** ffff
** File description:
** ffff
*/

#include "../include/my.h"
#include "../include/my_l.h"
#include <stdio.h>
#include <stdlib.h>

struct s_hp
{   int is_num;
    int was_num;
    int was_sign; 
};



dstar_t *separate_expr(char *expr)
{
    dstar_t *stck = init_dstar();
    dlist_t *numsl = init_dlist();
    int is_num = 0;
    int was_num = -1;
    int was_sign = -1;
    int i;

    for (i = 0; expr[i] != '\0'; i++) {
        check_if_num(expr[i], &is_num);
        if (i > 0) {
            check_if_num(expr[i - 1], &was_num);
            check_if_sign(expr[i - 1], &was_sign);
        }
        if (is_num == 1 && was_num == 1) {
            push_dlist(numsl, my_tostr(expr[i]));
        }
        if (is_num) {
            clear_dlist(numsl);
            push_dlist(numsl,my_tostr(expr[i]));
            push_dstar(stck,numsl->value);
        }
        else
        {
            push_dstar(stck,my_tostr(expr[i]));
        }
    }
    return (stck);
}

// dstar_t *separate_expr(char *expr)
// {
//     dstar_t *stck = init_dstar();
//     dlist_t *numsl = init_dlist();
//     int is_num = 0;
//     int was_num = -1;
//     int was_sign = -1;
//     int i;

//     for (i = 0; expr[i] != '\0'; i++) {
//         check_if_num(expr[i], &is_num);
//         if (i > 0) {
//             check_if_num(expr[i - 1], &was_num);
//             check_if_sign(expr[i - 1], &was_sign);
//         }
//         if (is_num == 1 && was_num == 1) {
//             push_dlist(numsl, my_tostr(expr[i]));
//         }
//         if (is_num) {
//             if(is_num)
//             push_dlist(numsl, my_tostr(expr[i]));
//         }
//         if(sign_w(expr[i])==0 && was_sign==1){
//             clear_dlist(numsl);
//             push_dlist(numsl,my_tostr(expr[i]));
//             push_dstar(stck,numsl->value);
//         }
        
//     }
//     return (stck);
// }

void pop_all(dstar_t *op, dstar_t *queu)
{
    int i = my_nolen(op) - 1;
    while (i >= 0) {
        push_dstar(queu, pop_dstar(op));
        i--;
    }
}

void close_par(dstar_t *op, dstar_t *queu)
{
    int i = (my_nolen(op) == 0) ? 0 : my_nolen(op) - 1;

    while (op->value[i][0] != '(' && i >= 0) {
        push_dstar(queu, pop_dstar(op));
        i--;
    }
    pop_dstar(op);
}
void pop_ops(char *about, dstar_t *op, dstar_t *queu)
{
    int i = (my_nolen(op) == 0) ? 0 : my_nolen(op) - 1;
    while (i >= 0 && sign_d(about, 1) <= sign_d(op->value[i], 1)) {
        push_dstar(queu, pop_dstar(op));
        i--;
    }
    push_dstar(op, about);
}

dstar_t *shunter(dstar_t *ced)
{
    dstar_t *queu = init_dstar();
    dstar_t *op = init_dstar();
    int is_num;

    for (int i = 0; i < my_nolen(ced); i++) {
        check_if_num(ced->value[i][0], &is_num);
        if (is_num)
            push_dstar(queu, ced->value[i]);
        if (sign_d(ced->value[i], 0) != 0) {
            pop_ops(ced->value[i], op, queu);
        }
        if (ced->value[i][0] == '(') {
            push_dstar(op, ced->value[i]);

        } else if (ced->value[i][0] == ')')
            close_par(op, queu);
    }
    pop_all(op, queu);
    return (queu);
}