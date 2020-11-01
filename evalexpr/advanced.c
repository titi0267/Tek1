/*
** EPITECH PROJECT, 2020
** bistromatic [WSL: Ubuntu]
** File description:
** advanced
*/

#include "../include/div_help.h"
#include "../include/my.h"
#include <stdlib.h>

int is_all_num(char *to_check)
{
    if (to_check[0] == '-' && check_nums(to_check[1]) ||
        check_nums(to_check[0])) {
        return (1);
    } else {
        return (0);
    }
}