/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** show
*/

#include "my_structs.h"
#ifndef SYNTAX_ERROR_MSG
#define SYNTAX_ERROR_MSG "syntax error"
#endif
#ifndef SHOW_H_
#define SHOW_H_
dstar_t *calculate(dstar_t *ced);
void make_calc(dstar_t *numbs,int sign);
number_t *op_doer(int sign ,char *y,char *x);

#endif /* !SHOW_H_ */