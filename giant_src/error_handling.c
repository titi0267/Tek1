/*
** EPITECH PROJECT, 2021
** error_handling by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** error_handling.c
*/

#include "../include/my.h"
#include "../include/my_struct.h"

int encoded_error(giant_t *buffer)
{
    int cut = 0;

    for (int i = 0; i < buffer->buffer_size; i++) {
        if (buffer->str[i] == '@')
            cut++;
    }
    if (cut == 3)
        return (0);
    my_printf("The encoding of this file is not handled by giantman, ");
    my_printf("see ./antman -h\n");
    return (84);
}

int error_arg(int ac, char **av)
{
    if (ac != 3 && ac != 2) {
        my_printf("Wrong amount of arguments, see ./antman -h.\n");
        return (84);
    }
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            print_usage();
            return (84);
        } else {
            my_printf("Wrong arguments, see ./antman -h.\n");
            return (84);
        }
    }
    if (ac == 3 && (av[2][0] != '1' && av[2][0] != '2' && av[2][0] != '3')) {
        my_printf("Wrong argument for file type.\n");
        return (84);
    }
    return (0);
}