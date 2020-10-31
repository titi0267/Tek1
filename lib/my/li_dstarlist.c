/*
** EPITECH PROJECT, 2020
** ff
** File description:
** ff
*/
#include "./include/my.h"
#include "./include/my_l.h"
#include <stdlib.h>


const char *MY_NULL="NO";


dstar_t *init_dstar()
{
    dstar_t *inited = malloc(sizeof(dstar_t));

    inited->mem_len = 10;
    inited->value = malloc(sizeof(char *) * inited->mem_len);
    for (int i = 0; i < (inited->mem_len - 1); i++) {
        inited->value[i] = my_strdup(MY_NULL);
    }
    inited->value[inited->mem_len - 1] = NULL;
    return (inited);
}
char *pop_dstar(dstar_t *to_pop)
{
    char *popped;
    int i = (my_nolen(to_pop) > 0) ? my_nolen(to_pop) : 1;

    popped = my_strdup(to_pop->value[i - 1]);
    free(to_pop->value[i - 1]);
    to_pop->value[i - 1] = my_strdup(MY_NULL);
    return (popped);
}

void push_dstar(dstar_t *to_push, char const *value)
{
    int i = 0;
    while (to_push->value[i] != NULL) {
        if (my_strcmp(to_push->value[i], MY_NULL) == 0)
            break;
        i++;
    }

    if (i >= (my_arrlen(to_push->value)))
        re_dstar(to_push);
    to_push->value[i] = malloc(1000);
    my_strcpy(to_push->value[i], value);
}

void re_dstar(dstar_t *to_re)
{
    int size = to_re->mem_len;
    char **my_new = malloc(to_re->mem_len * 2 * sizeof(char *));
    int i;

    for (i = 0; (size - 1) > i; i++) {
        my_new[i] = my_strdup(to_re->value[i]);
        free(to_re->value[i]);
    }
    free(to_re->value);

    for (i = size - 1; (size * 2) > i; i++) {
        my_new[i] = my_strdup(MY_NULL);
    }

    my_new[i - 1] = NULL;
    to_re->value = my_new;
    to_re->mem_len = size * 2;
}

void sh_dstar(dstar_t *dt)
{
    for (int i = 0; dt->value[i] != NULL; i++) {
        my_putstr(dt->value[i]);
        my_putstr("\n");
    }
    my_put_nbr(dt->mem_len);
    my_putchar('\n');
}

