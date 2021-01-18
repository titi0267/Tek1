/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL & Sylvian BURN
** File description:
** main.c
*/

#include "../include/my.h"

void store_arg(input_t *inp, char **av)
{
    for (int i = 1; i <= 7; i++) {
        switch (i) {
            case 1:
                inp->opt = my_getnbr(av[i]);
                break;
            case 2:
                inp->a0 = my_getnbr(av[i]);
                break;
            case 3:
                inp->a1 = my_getnbr(av[i]);
                break;
            case 4:
                inp->a2 = my_getnbr(av[i]);
                break;
            case 5:
                inp->a3 = my_getnbr(av[i]);
                break;
            case 6:
                inp->a4 = my_getnbr(av[i]);
                break;
            case 7:
                inp->n = my_getnbr(av[i]);
                break;
            default:
                break;
        }
    }
}

int main(int ac, char **av)
{
    input_t *inp = malloc(sizeof(input_t));

    if (inp == NULL || error_handling(ac, av) != 0)
        return (84);
    store_arg(inp, av);
    return (0);
}