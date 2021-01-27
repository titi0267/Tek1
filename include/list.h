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
    long long int nbr;
    struct list_t *next;
};

struct seclist_t
{
    long long int num;
    struct seclist_t *next;
};

typedef struct in_b
{
    long long int max;
    long long int size;
    long long int store_size;
    long long int low;
} in_b_t;

#endif /* !LIST_H_ */
