/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** polish
*/

#ifndef SYNTAX_ERROR_MSG
#define SYNTAX_ERROR_MSG "syntax error"
#endif
#pragma once
dstar_t *shunter(dstar_t *ced);
void pop_ops(char *about,dstar_t *op,dstar_t *queu);
void close_par(dstar_t *op,dstar_t *queu);
void pop_all(dstar_t *op,dstar_t *queu);
dstar_t *separate_expr(char *expr);
int is_all_num(char *to_check);