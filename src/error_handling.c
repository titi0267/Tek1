/*
** EPITECH PROJECT, 2020
** error_handling.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** error_handling
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>

int str_handling(char c)
{
    if (c >= 65 || c <= 90 || c >= 97 || c <= 122 || c == 32)
        return (0);
    else {
        my_puterr("Error: The string can only be composed of alphabetical characters\n");
        return (84);
    }
}

int error_handling(int ac, char **av)
{
    if (ac != 4) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            usage(ac, av);
            return (84);
        }
        else {
            my_puterr("Invalid argument input\n");
            return (84);
        }
    }
    if (ac == 4) {
        for (int i = 1; i <= 2; i++) {
            for (int j = 0; av[i][j] != '\0'; j++) {
                if (str_handling == 84)
                    return (84);
            }
        }
    }
    if (av[3][0] != '0' || av[3][0] != '1') {
        my_puterr("Invalid encrypting/decrypting key flag (See Usage for more info)\n");
        return (84);
    }
    return (0);
}