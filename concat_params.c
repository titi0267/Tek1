/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** 
*/
#include <stdlib.h>

int my_putstr(char const *str);
int my_strlen(char const *str);

char *concat_params(int argc , char **argv)
{
    int i = 0;
    int x = 0;
    int j = 0;
    char *str;
    //int c = my_strlen(str);

    str = malloc(sizeof(char) * (argc + 1));
    for (i = 0; i < argc; i+= 1) {
        for (j = 0; argv[i][j] != '\0'; j += 1) {
            str[x] = argv[i][j];
            x = x + 1;
            //str[x] = '\n';
        }
        str[i] = '\n';
        str[x] = '\0';
        j = 0;
    }
    return (str);
}

int  main(int ac , char **av)
{
    my_putstr(concat_params(ac, av));
    return (0);
}