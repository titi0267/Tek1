/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include "op.h"
#include "list.h"

int my_getnbr(char *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_putnbr(int nb);
void print_list(struct list_t *list);
void delete(struct list_t *list);
int insert(struct list_t **list, int new_nbr);

#endif /* !MY_H_ */
