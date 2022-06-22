// Epitech
// Solo_Stumper
// File description
// main.c
#include <stdio.h>
#include <stdlib.h>

#ifndef MY_STRUCT
#define MY_STRUCT

typedef struct counter_s
{
    int i;
    int c;
    int check;
    int r;
    int how_m;
    int *word_num;
}counter_t;
#endif /*MY_STRUCT*/


int store(char **av, char **str)
{
    int i = 0;
    int c = 0;
    int r = 0;

    for (; av[i] != 0; i++) {
        for (; av[i][r] != '\0'; r++);
        str[i] = malloc(sizeof(char) * r + 1);
        for (; av[i][c] != '\0'; c++) {
            str[i][c] = av[i][c];
        }
        c = 0;
        r = 0;
   }
    return (0);
}

int count_word_next(char **av, char **str, counter_t *counter)
{
    counter->check = 0;
    for (; av[counter->i][counter->c] != '\0'; counter->c++) {
            if (av[counter->i][counter->c] == str[counter->r][counter->c])
                counter->check++;
        }
    if (counter->check == counter->c) {
        return (counter->how_m++);
    }
    return (0);
}

int count_word(int ac, char **av, char **str, counter_t *counter)
{
    int many = 0;
    int number = 0;

    counter->how_m = 1;
    counter->c = 0;
    counter->i = 1;
    counter->r = 1;
    counter->word_num = malloc(sizeof(int) * ac + 1);
    for (; counter->r < ac; counter->r++) {
        for (; av[counter->i] != 0; counter->i++) {
            many = count_word_next(av, str, counter);
            if (many > 0)
                number++;
            if (many == 0)
                number = 0;
            counter->c = 0;
        }
        counter->word_num[counter->r] = counter->how_m;
        counter->how_m = 0;
        counter->i = 1;
    }
}

int print_word(char **av, counter_t *counter)
{
    int r = 0;
    counter->i = 0;
    for (int i = 1; av[i] != 0; i++) {
            printf("%s: %i\n", av[i], counter->word_num[i]);
    }
    return (0);
}
int error_handle(int ac)
{
    if (ac <= 1) {
        printf("\n");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    counter_t *counter = malloc(sizeof(counter_t));
    char **str = malloc(sizeof(char *) * (ac +1));

    if (error_handle(ac) == 84)
        return(84);
    store(av, str);
    count_word(ac, av, str, counter);
    print_word(av, counter);
    return (0);
}
