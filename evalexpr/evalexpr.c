/*
** EPITECH PROJECT, 2020
** hhfhfhf
** File description:
** fhfhfh
*/

#include "../include/my.h"
#include "../include/my_l.h"
#include "../include/polish.h"
#include "../include/show.h"
#include "../include/my_structs.h"
#include <stdio.h>
#include <stdlib.h>



int run_expr(char *num)
{
    dstar_t *runner;
    runner = separate_expr(num);
    runner = shunter(runner);
    runner = calculate(runner);
    my_putstr(runner->value[0]);
    my_putstr("\n");
}

int main(int ac, char **av) { 
run_expr(my_strdup(av[1])); 
}