/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/
#include "put.h"

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
    return (0);
}