/*
** EPITECH PROJECT, 2020
** ffff
** File description:
** ffff
*/

#include "./include/my.h"
#include "./include/my_lists.h"
#include <stdio.h>
#include <stdlib.h>

my_stack_t *separate_expr(char *expr)
{
    my_stack_t *stck = my_init();
    int is_num = 0;
    int was_num = -1;
    int i;

    for (i = 0; expr[i] != '\0'; i++) {
        check_if_num(expr[i], &is_num);
        if (i > 0)
            check_if_num(expr[i - 1], &was_num);
        if (is_num == 1 && was_num == 1) {
            my_strcat(stck->value[my_nolen(stck->value) - 1],
                      my_tostr(expr[i]));
        } else if (is_num)
            my_push(stck, my_tostr(expr[i]));
        else
            my_push(stck, my_tostr(expr[i]));
    }
    return (stck);
}

void pop_all(my_stack_t *op, my_stack_t *queu)
{
    int i = my_nolen(op->value) - 1;
    while (i >= 0) {
        my_push(queu, my_pop(op));
        i--;
    }
}

void close_par(my_stack_t *op, my_stack_t *queu)
{
    int i = (my_nolen(op->value) == 0) ? 0 : my_nolen(op->value) - 1;

    while (op->value[i][0] != '(' && i >= 0) {
        my_push(queu, my_pop(op));
        i--;
    }
    my_pop(op);
}
void pop_ops(char *about, my_stack_t *op, my_stack_t *queu)
{
    int i = (my_nolen(op->value) == 0) ? 0 : my_nolen(op->value) - 1;
    while (i >= 0 && sign_d(about, 1) <= sign_d(op->value[i], 1)) {
        my_push(queu, my_pop(op));
        i--;
    }
    my_push(op, about);
}

my_stack_t *shunter(my_stack_t *ced)
{
    my_stack_t *queu = my_init();
    my_stack_t *op = my_init();
    int is_num;

    for (int i = 0; i < my_nolen(ced->value); i++) {
        check_if_num(ced->value[i][0], &is_num);
        if (is_num)
            my_push(queu, ced->value[i]);
        if (sign_d(ced->value[i], 0) != 0) {
            pop_ops(ced->value[i], op, queu);
        }
        if (ced->value[i][0] == '(') {
            my_push(op, ced->value[i]);

        } else if (ced->value[i][0] == ')')
            close_par(op, queu);
    }
    pop_all(op, queu);
    return (queu);
}