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

void checks_one_part_two(read_t *rd);
void checks_one(read_t *rd);
void checks_two(read_t *rd);
void checks_three(read_t *rd);
void checks_four(read_t *rd);
void checks_five(read_t *rd);
void checks_six(read_t *rd);
void checks_seven(read_t *rd);
void checks_eight(read_t *rd);

int read_maze(read_t *rd, char **av);
int replace_nbr(read_t *rd);
void increment(read_t *rd);
void replace_solve(read_t *rd);

void free_func(solve_t *slv);

void checks_two_next(read_t *rd);
void checks_three_next(read_t *rd);

int error_entry(read_t *rd);

#endif /* !SOLVE_H_ */
