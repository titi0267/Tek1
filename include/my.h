/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include "list.h"

int my_getnbr(char *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_putnbr(int nb);
void print_alist(struct list_t *list);
void delete(struct list_t *list);
int insert(struct list_t **list, int new_nbr);
int rra(struct list_t **list);
int sa(struct list_t **list);
int ra(struct list_t **list, struct seclist_t **list_b, in_b_t *value);
int pb(struct seclist_t **list_b, struct list_t **list);
void delete_b(struct seclist_t *list_b);
int rrb(struct seclist_t **list_b);
int rb(struct seclist_t **list_b);
int sb(struct seclist_t **list_b);
int sort_all(struct list_t **list, struct seclist_t **list_b, in_b_t *value);
void find_max(struct list_t **list, in_b_t *value);
int max_val(struct list_t **list, struct seclist_t **list_b, in_b_t *value);
int pa(struct seclist_t **list_b, struct list_t **list);
int print_blist(struct seclist_t *list_b, struct list_t *list);
void size_a(struct list_t **list, in_b_t *value);
void print_alist(struct list_t *list);
void loop(struct list_t **list, struct seclist_t **list_b);
int compare_a(struct list_t **list, struct seclist_t **list_b, in_b_t *value);
int sorted(struct list_t **list, struct seclist_t **list_b, in_b_t *value);

#endif /* !MY_H_ */
