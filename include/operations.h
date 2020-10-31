/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** operations
*/

#pragma once
int my_nblen(char *num);
void clear_o(char *witho);
number_t *driver(number_t *one,number_t *two,opossom_t *ops,char(*sum_f)(char,char,int *));
number_t *calc_f(number_t *one,number_t *two,opossom_t *ops);
char subst(char a,char b,int *indi);
char sum(char a,char b,int *indi);