/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** polish
*/

#include "my_l.h"
#ifndef POLISH_H_SURE
#define POLISH_H_SURE
dstar_t *shunter(dstar_t *ced);
void pop_ops(char *about,dstar_t *op,dstar_t *queu);
void close_par(dstar_t *op,dstar_t *queu);
void pop_all(dstar_t *op,dstar_t *queu);
dstar_t *separate_expr(char *expr);
int is_all_num(char *to_check);
#endif /* !POLISH_H_SURE */