/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Displays a number in a given base
*/

#include "../../include/misc.h"
#include "../../include/my.h"
#include "../../include/my_struct.h"
#include <string.h>

int my_putnbr_base(int number, const char *base, infin_number_t *info)
{
    return (my_putnbr_base_width(number, base, 0, info));
}
