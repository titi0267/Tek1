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




int check_newnum(char *num, int pos, int *numcheck)
{

    if(num[pos] == '-' && check_nums(num[pos + 1])){
        if(pos == 0 || sign_w(num[pos - 1]) != 0 || num[pos - 1] == '(') {
         *numcheck = 1;
         return (1);
        } else
        {
            *numcheck = 0;
            return (0);
        }
        
    } else if (check_nums(pos) && numcheck == 0) {
         *numcheck = 1;
         return (1);
    }
    else
    {
        *numcheck = 0;
        return (0);
    }
}

dstar_t *separate_expr(char *expr)
{
    dstar_t *stck = init_dstar();
    dlist_t *numsl = init_dlist();
    int is_num = 0;
    int was_num = 0;
    int was_sign = -1;
    int numcheck = 0;
    int i;

    for (i = 0; expr[i] != '\0'; i++) {
        check_if_num(expr[i], &is_num);
        if (i > 0) {
            check_if_num(expr[i - 1], &was_num);
            check_if_sign(expr[i - 1], &was_sign);
        }
        if(check_newnum(expr, i, &numcheck)) {
            printf("check_newnum(expr, i, &numcheck");
            push_dlist(numsl,my_tostr(expr[i]));
        }
        else if (is_num) {
            printf("is_num");
            push_dlist(numsl,my_tostr(expr[i]));
        }
        if(check_nums(expr[i+1])==0 && is_num == 1){
            printf("check_nums(expr[i+1])==0 && was_num == 1\n");
            push_dstar(stck,numsl->value);
            clear_dlist(numsl);
        }
        if(is_num == 0 && numcheck == 0)
        {
            printf("is_num == 0\n");
            push_dstar(stck, my_tostr(expr[i]));
        }
        printf("i est %d\n",i);
        sh_dstar(stck);
        printf("_______________________________");
        printf("\n");
    }
    return (stck);
}

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