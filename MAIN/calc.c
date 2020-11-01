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
    int i = 0;

    while (read(0 ,store + i, 1) != 0 && i < amount){
        if (store[i] == '\n')
            break;
        i++;
    }
    store[i] = '\0';
    return (store);
}

void *tell_dumy_user(void)
{
        my_putstr("USAGE\n");
        my_putstr("./calc base operators size_read\n\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("- base: all the symbols of the base\n");
        my_putstr("- operators: the symbols for the parentheses and the 5 operators\n");
        my_putstr("- size_read: number of charachters to be read\n");
}

int main(int ac, char **av)
{
    if (av[1] != NULL && my_strcmp(av[1], "-h") == 0) {
        tell_dumy_user();
        return (0);
    }
    if (ac != 4) {
        write(2, ERROR_MSG, 18);
        return (84);
    }
    int amount = my_getnbr(av[3]);
    char *reads = read_all(amount);
    replace_signs(av[2], reads);
    run_expr(reads);
}