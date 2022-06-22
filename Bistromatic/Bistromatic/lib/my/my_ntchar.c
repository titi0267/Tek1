/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_ntchar.c
*/

#include "./include/my.h"
#include <stdlib.h>

char *my_ntchar(int nb)
{
    int currents;
    char *ft = malloc(15);
    int count = 0;

    if (!check_if_p(nb)) {
        ft[count] = '-';
        count++;
        nb = nb * -1;
    }
    for (int k = 1; k <= lengthsp(nb); k++) {
        currents = (nb / pow_ten(lengthsp(nb) - k)) % 10;
        ft[count] = (currents + 48);
        count++;
    }
    ft[count] = '\0';
    return (ft);
}
