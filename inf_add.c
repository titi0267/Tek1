/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-infinadd-timothe.coniel
** File description:
** inf_add
*/
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add(char *gauche, char *droite)
{
    int retenue = 0;
    int i = 0;
    char *res = malloc(sizeof(char) * (my_strlen(gauche) + my_strlen(droite) + 8));

    gauche = my_revstr(gauche);
    droite = my_revstr(droite);
    for (; droite[i] != '\0'; i += 1) {
        int add = gauche[i] + droite[i] - 48 - 48;
        if (add >= 10) {
            res[i] = add - 10 + 48 + retenue;
            retenue = 1;
        } else {
            res[i] = add + 48 + retenue;
            retenue = 0;
        }
    }
    for (; gauche[i] != '\0'; i += 1) {
        int add = gauche[i] - 48;
        if (add >= 10) {
            res[i] = add - 10 + 48 + retenue;
            retenue = 1;
        } else {
            res[i] = add + 48 + retenue;
            retenue = 0;

        }
    }
    res[i] = '\0';
    return (my_revstr(res));
    free(res);
}

int main(int ac, char **av)
{
    char *gauche;
    char *droite;

    if (gauche < droite) {
        droite = av[1];
        gauche = av[2];
    } else {
        gauche = av[1];
        droite = av[2];
    }
    my_putstr(add(gauche, droite));
}