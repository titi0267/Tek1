/*
** EPITECH PROJECT, 2020
** 102architect.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** 102architect
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_struct.h"

int architect_core(char **av, infin_number_t *info)
{

}

int main(int ac, char **av)
{
    int to_return = 0;
    infin_number_t *info = malloc(sizeof(infin_number_t));

    to_return = architect_core(av, info);
    if (to_return == 0) {
        return (info->amount);
    }
}