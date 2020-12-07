/*
** EPITECH PROJECT, 2020
** cipher.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** cipher
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void usage(void)
{
        printf("USAGE\n    ./103cipher message key flag\n\nDESCRIPTION\n");
        printf("    message    a message, made of ASCII characters\n");
        printf("    key        the encryption key, made of ASCII characters\n");
        printf("    flag       0 for the message to be encrypted, 1 to be decrypted\n");
}

void de_encrypt(char **av)
{
    if (av[3][0] == '1')
        printf("\nDecrypted message:\n");
    if (av[3][0] == '0')
        printf("\nEncrypted message:\n");
}

int main(int ac, char **av)
{
    infin_number_t *info = malloc(sizeof(infin_number_t));

    if (error_handling(ac, av) != 0)
        return (84);
    print_matrix(av, info);
    de_encrypt(av);
    encrypt_3(av, info);
    return (0);
}