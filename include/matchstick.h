/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include  "../lib/my/my.h"
#include "struct.h"

int error_wrong_arg(int ac, char **av);

int map_created(map_t *map, char **av);

void take_line_input(user_t *user);
int get_user_input(user_t *user);

#endif /* !DEFENDER_H_ */
