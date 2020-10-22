/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-infinadd-sylvian.burn
** File description:
** my_isneg.c
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
