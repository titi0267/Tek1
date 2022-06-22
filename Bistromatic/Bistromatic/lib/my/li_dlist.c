/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** li_dlist.c
*/

#include "include/my.h"
#include "include/my_l.h"
#include <stdlib.h>

dlist_t *init_dlist(void)
{
    dlist_t *inited = malloc(sizeof(dlist_t));

    inited->value = malloc(10);
    inited->value[0] = '\0';
    inited->mem_len = 10;
    return(inited);
}

void sh_dlist(dlist_t *to_sh){
    my_putstr("dlist: ");
    my_putstr(to_sh->value);
    my_putstr("\n");
    my_putstr("memory: ");
    my_put_nbr(to_sh->mem_len);
    my_putstr("\n");
}

static void re_dlist(dlist_t *to_push)
{
    to_push->mem_len = to_push->mem_len * 2;
    char *new_str = malloc(to_push->mem_len);
    my_strcpy(new_str, to_push->value);
    free(to_push->value);
    to_push->value = new_str;
}

void push_dlist(dlist_t *to_push, char *str)
{
    int tot_len = my_strlen(to_push->value) + my_strlen(str) +1;

    while ((tot_len) >= to_push->mem_len) {
        re_dlist(to_push);
    }
    my_strcat(to_push->value,my_strdup(str));
}

void clear_dlist(dlist_t *to_clear)
{
    free(to_clear->value);
    to_clear->value=malloc(10);
    my_strcpy(to_clear->value,"");
    to_clear->mem_len=10;
}