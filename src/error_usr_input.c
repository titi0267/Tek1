/*
** EPITECH PROJECT, 2021
** error_usr_input by Timothy CONIEL
** File description:
** Errors on inputs to remove matches on a certain line
*/

#include "../include/matchstick.h"


int take_line_input(user_t *user, map_t *map)
{
    for (int i = 0; user->str[i] != '\n'; i++) {
        if (user->str[i] < 48 || user->str[i] > 57) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (ERROR);
        }
    }
    user->line = my_getnbr(user->str);
    if (user->line <= 0 || user->line > map->line_nbr) {
        my_printf("Error: this line is out of range\n");
        return (ERROR);
    }
    return (0);
}

int enough_matches(user_t *user, map_t *map)
{
    int count_matches = 0;

    for (int i = 0; map->map[user->line][i] != '\n'; i++) {
        if (map->map[user->line][i] == '|')
            count_matches++;
    }
    return (count_matches);
}

int take_match_input(user_t *user, map_t *map)
{
    for (int i = 0; user->str[i] != '\n'; i++) {
        if (user->str[i] < 48 || user->str[i] > 57) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (ERROR);
        }
    }
    user->matches = my_getnbr(user->str);
    if (user->matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (ERROR);
    } else if (user->matches > map->match_max) {
        my_printf("Error: you cannot remove more than %i matches per turn\n",
                map->match_max);
        return (ERROR);
    }
    if (enough_matches(user, map) < user->matches) {
        my_printf("Error: not enough matches on this line\n");
        return (ERROR);
    }
    return (0);
}