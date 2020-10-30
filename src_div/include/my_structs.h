/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_structs
*/

#ifndef YO_H
#define YO_H
typedef struct number {
    char *numb;
    int sign;
} number_t;

typedef struct opossom
{
    int op;
    int sign;
} opossom_t;
number_t *infin_add(char *n1, char *n2);

#endif 