/*
** EPITECH PROJECT, 2021
** solo_stumper by Timothy CONIEL
** File description:
** solo_stumper.c
*/

#include <unistd.h>
#include <stdio.h>

int my_strncmp(char *cmp, char *cmpd);
int my_putstr(char const *str);
int my_putnbr(int nb);
int my_getnbr(char *str);
void my_putchar(char c);
int error(int ac, char **av);

int is_mult2(int i)
{
    if ((i % 2) == 0 && (i % 9) != 0)
        return (1);
    return (0);
}

int is_mult9(int i)
{
    if ((i % 9) == 0 && (i % 2) != 0)
        return (1);
    if ((i % 9) == 0 && (i % 2) == 0)
        return (2);
    return (0);
}

void print_num(char **av)
{
    int i = my_getnbr(av[1]);

    for (; i <= my_getnbr(av[2]); i++) {
        if (is_mult9(i) == 2)
            printf("FoozBazz\n");
        if (is_mult2(i) == 1)
            printf("Fozz\n");
        if (is_mult9(i) == 1)
            printf("Bazz\n");
        if (is_mult2(i) == 0 && is_mult9(i) == 0)
            printf("%i\n", i);
    }
}

int main(int ac, char **av)
{
    if (error(ac, av) != 0) {
        return (84);
    }
    print_num(av);
    return (0);
}
