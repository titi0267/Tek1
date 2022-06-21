/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday08-lilou.stoll-metz
** File description:
** concat_params
*/
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    char *str;
    int k = 0;
    int len = 0;

    for (int j = 0; j < argc; j++)
        len += my_strlen(argv[j]) + 1;
    str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < my_strlen(argv[i]); j++) {
            str[k] = argv[i][j];
            k++;
        }
        str[k] = '\n';
        k++;
    }
    str[k - 1] = '\0';
    return (str);
}