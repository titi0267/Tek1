/*
** EPITECH PROJECT, 2020
** hhfhfhf
** File description:
** fhfhfh
*/

#include "include/my_lists.h"
#include "include/my.h"
#include "include/polish.h"
#include <stdio.h>
#include <stdlib.h>

const char *MY_NULL = "NO";


my_stack_t *my_init()
{
    my_stack_t *inited = malloc(sizeof(my_stack_t));

    inited->mem_len = 10;
    inited->value = malloc(sizeof(char *) * inited->mem_len);
    for (int i = 0; i < (inited->mem_len - 1); i++) {
        inited->value[i] = my_strdup(MY_NULL);
    }
    inited->value[inited->mem_len - 1] = NULL;
    return (inited);
}
char *my_pop(my_stack_t *to_pop)
{
    char *popped;
    int i;
    for (i = 0; to_pop->value[i] != NULL; i++) {
        if (my_strcmp(to_pop->value[i], MY_NULL) == 0)
            break;
    }

    popped = my_strdup(to_pop->value[i - 1]);
    free(to_pop->value[i - 1]);
    to_pop->value[i - 1] = my_strdup(MY_NULL);
    return (popped);
}

void my_push(my_stack_t *to_push, char const *value)
{
    int i = 0;
    while (to_push->value[i] != NULL) {
        if (my_strcmp(to_push->value[i], MY_NULL) == 0)
            break;
        i++;
    }

    if (i >= (my_arrlen(to_push->value)))
        my_realloc(to_push);
    to_push->value[i] = malloc(5);
    my_strcpy(to_push->value[i], value);
}

void my_realloc(my_stack_t *to_re)
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


int run_expr(int ac, char **av){
    my_stack_t *runner;


    if(ac==2)
    {
        runner=separate_expr(av[1]);
        
    }
}