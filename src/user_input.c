/*
** EPITECH PROJECT, 2021
** user input by Timothy CONIEL
** File description:
** recover user input
*/

#include "../include/matchstick.h"

int get_usr_line(user_t *user, map_t *map)
{
    size_t len = 0;

    while (1) {
        len = 0;
        user->str = NULL;
        my_printf("Line: ");
        if (getline(&user->str, &len, stdin) != -1) {
            if (take_line_input(user, map) == 0)
                return (0);
        } else {
            my_printf("\n");
            return (2);
        }
    }
    return (0);
}

int get_usr_match(user_t *user, map_t *map)
{
    size_t len = 0;
    int ret_input = 0;

    while (1) {
        len = 0;
        user->str = NULL;
        my_printf("Matches: ");
        if (getline(&user->str, &len, stdin) != -1) {
            ret_input = take_match_input(user, map);
            if (ret_input == ERROR)
                get_usr_line(user, map);
            if (ret_input == 0)
                return (0);
        } else {
            my_printf("\n");
            return (2);
        }
    }
    return (0);
}

int user_turn(map_t *map, user_t *user)
{
    my_printf("\nYour turn:\n");
    if (get_usr_line(user, map) == 2)
        return (1);
    if (get_usr_match(user, map) == 2)
        return (1);
    my_printf("Player removed %i match(es) from line %i\n",
            user->matches, user->line);
    remove_matches_usr(map, user);
    for (int i = 0; map->map[i] != NULL; i++)
        my_printf("%s", map->map[i]);
    is_pipe_user(map, user);
    return (0);
}

int main_loop(core_t *core)
{
    while (1) {
        if (user_turn(core->map, core->user) == 1)
            return (1);
        if (core->user->lose == TRUE)
            break;
        ai_turn(core->map, core->ai);
        if (core->ai->lose == TRUE)
            break;
    }
    return (0);
}