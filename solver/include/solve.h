/*
** EPITECH PROJECT, 2021
** solve
** File description:
** solve.h
*/

#ifndef SOLVE_H_
#define SOLVE_H_

#include "../../include/my.h"
#include "struct.h"
#include "defined.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

int malloc_struct(solve_t *slv);

int read_maze(read_t *rd, char **av);
int replace_nbr(read_t *rd);
void increment(read_t *rd);
void replace_solve(read_t *rd);

void free_func(solve_t *slv);

#endif /* !SOLVE_H_ */
