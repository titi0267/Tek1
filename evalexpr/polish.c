/*
** EPITECH PROJECT, 2020
** ffff
** File description:
** ffff
*/

#include "./include/my_l.h"
#include "./include/my.h"
#include <stdio.h>
#include <stdlib.h>

dstar_t *separate_expr(char *expr)
{
    dstar_t *stck = init_dstar();
    int is_num = 0;
    int was_num = -1;
    int i;
    char *handler=NULL;

    for (i = 0; expr[i] != '\0'; i++) {
        check_if_num(expr[i], &is_num);
        if (i > 0)
            check_if_num(expr[i - 1], &was_num);
        if (is_num == 1 && was_num == 1) {
            my_strcat(stck->value[my_nolen(stck) - 1], my_tostr(expr[i]));
        } else if (is_num) {
            handler = malloc(1000); // malloc bourin
            my_strcpy(handler, my_tostr(expr[i]));
            push_dstar(stck, handler);
        } else
            push_dstar(stck, my_tostr(expr[i]));
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