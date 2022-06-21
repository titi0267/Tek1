/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include  "../lib/my/my.h"
#include "struct.h"

int error_wrong_arg(int ac, char **av);

int map_created(map_t *map, char **av);

int take_line_input(user_t *user, map_t *map);
int take_match_input(user_t *user, map_t *map);
void remove_matches_usr(map_t *map, user_t *user);
int count_line_remain(map_t *map);

void ai_choice(ai_t *ai, map_t *map);
void remove_matches_ai(map_t *map, ai_t *ai);
void is_pipe_ai(map_t *map, ai_t *ai);
void ai_turn(map_t *map, ai_t *ai);

int main_loop(core_t *core);
int who_lost(core_t *core);
void is_pipe_user(map_t *map, user_t *user);

void free_struct(core_t *core);

#endif /* !DEFENDER_H_ */
