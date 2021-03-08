/*
** EPITECH PROJECT, 2021
** change map by Timothy CONIEL
** File description:
** change map by user inputs
*/

#include "../include/matchstick.h"

void remove_matches_usr(map_t *map, user_t *user)
{
    int removed = 0;

    for (int i = 0; map->map[user->line][i] != '\n'; i++) {
        if (map->map[user->line][i] == '|' && removed != user->matches) {
            removed++;
            map->map[user->line][i] = ' ';
        }
    }
}

void remove_matches_ai(map_t *map, ai_t *ai)
{
    int removed = 0;

    for (int i = 0; map->map[ai->line_chosen][i] != '\n'; i++) {
        if (map->map[ai->line_chosen][i] == '|' &&
            removed != ai->matches_to_rm) {
            removed++;
            map->map[ai->line_chosen][i] = ' ';
        }
    }
}