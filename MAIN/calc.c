/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** calc
*/
#include "../include/calc.h"
#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>

char *read_all(int amount)
{
    char *store = malloc(amount + 1);

    read(0, store, amount);
    store[amount] = '\0';
    return (store);
}

int main(int ac, char **av) 
{
    int amount = my_getnbr(av[3]);
    char *reads = read_all(amount);
    replace_signs(av[2], reads);
    run_expr(reads);
}