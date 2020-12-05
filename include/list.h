/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

struct list_t
{
    int nbr;
    struct list_t *next;
};

struct seclist_t
{
    int num;
    struct seclist_t *next;
};

typedef struct in_b
{
    int max;
    int size;
    int store_size;
} in_b_t;


#endif /* !LIST_H_ */
